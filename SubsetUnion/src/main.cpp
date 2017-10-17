//============================================================================

// Name        : main.cpp

// Author      :

// Version     :

// Copyright   : Your copyright notice

// Description : Hello World in C++, Ansi-style

//============================================================================

//Tuple: iterate with size() and get<0>
//https://msdn.microsoft.com/en-us/library/dn439779.aspx

//source: https://www.murrayc.com/permalink/2015/12/05/modern-c-variadic-template-parameters-and-tuples/

#include <omp.h>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <memory>

#include "Bag.hpp"
#include "Union.hpp"
#include "Subset.hpp"
#include "SubsetUnion.hpp"

using namespace std;

//___________________________________________________________________________________
//
// Example for usage of Subset and union using Simplified UML-like - Metamodel classes

class Element
{
public:
    // Union for all Elements
    std::shared_ptr<Union<Element>> ownedElement;

    Element()
    {
        ownedElement.reset(new Union<Element>());
    }

    virtual ~Element(){}

};

class NamedElement : public Element
{

private:
    string m_name = "_";
public:

    NamedElement(){}

    virtual ~NamedElement(){}

    void setName(const string &name)
    {
        m_name = move(name);
    }

    void print()
    {
        std::cout << "my name is: " << m_name;
    }
};

class PackageableElement : public NamedElement
{
public:
    PackageableElement()
    {
    }
};

class Namespace : public NamedElement
{

public:
    std::shared_ptr<Union<NamedElement>> member; // Union for namespace members (see UML specification)

    std::shared_ptr<SubsetUnion<NamedElement, Element, NamedElement>> ownedMember; // First NamedElement: Type of attribute; Element: Type of first Union --> Element::ownedElement; Second NamedElement: Type of second Union: Namespace::member

    std::shared_ptr<Union<Element>> additionalTestUnion; // Additional Union for an additional example

    std::shared_ptr<Subset<PackageableElement, NamedElement, Element, NamedElement>> importedMember; // extendet Example - PackageableElement: Type of attribute; NamedElement, Element and NamedElement Unions

    Namespace()
    {
	   // Create Members using subset and Union (see UML specification)
        member = std::shared_ptr<Union<NamedElement> >(new Union<NamedElement>());
        ownedMember.reset(new SubsetUnion<NamedElement, Element, NamedElement>(ownedElement, member));

	   // additional test case
        additionalTestUnion = std::shared_ptr<Union<Element> >(new Union<Element>());
        importedMember.reset(new Subset<PackageableElement, NamedElement, Element, NamedElement>(member, additionalTestUnion, member));
    }
};

class Package : public Namespace, public PackageableElement
{
public:
    std::shared_ptr<Subset<PackageableElement, NamedElement>> packagedElement;
    Package(){ }
    virtual ~Package() { }
};

//___________________________________________________________________________________
//
// Secont example to creation and destruction of subset and union instances

class K1
{
public:
    K1() {}

    virtual void print()
    {
        cout << "K1!" << endl;
    }

    virtual ~K1()
    {
        std::cout << "K1: ~~~~~~~~~~~~~~~~~" << std::endl << std::flush;
    }
};

class K2 : public K1
{
private:
    int attribute;
public:
    explicit K2(int val)
    {
        attribute = val;
    }

    void print()
    {
        std::cout << "K2: Value is " << attribute << std::endl;
    }

    virtual ~K2()
    {
        std::cout << "K2: ~~~~~~~~~~~~~~~~~" << std::endl << std::flush;
    }
};

class K4 : public K1
{
    int attribute;
public:
    explicit K4(int val)
    {
        attribute = val;
    }

    void print()
    {
        cout << "K4: Value is " << attribute << endl;
    }

    virtual ~K4()
    {
        cout << "K4: ~~~~~~~~~~~~~~~~~" << endl;
    }
};

class K3
{
private:
    shared_ptr<Union<K1>> unionK1;
    shared_ptr<SubsetUnion<K2, K1>> cl;
    shared_ptr<Subset<K2, K1>> subK2K1;
    shared_ptr<Subset<K4, K1>> subK4K1;
public:
    K3()
    {
        unionK1.reset(new Union<K1>());
        subK2K1.reset(new Subset<K2, K1>(unionK1));
        subK4K1.reset(new Subset<K4, K1>(unionK1));
        subK2K1->add(shared_ptr<K2>(new K2(2)));
        subK4K1->add(shared_ptr<K4>(new K4(4)));
    }

    void print()
    {
        for (std::vector<std::shared_ptr<K1> >::const_iterator it = unionK1->begin(); it != unionK1->end();
             ++it)
        {
            cout << "K3: Value is ";
            (*it)->print();
            cout << endl;
        }

    }

    virtual ~K3()
    {
        cout << "K3: Start ~~~~~~~~~~~~~~~~~" << endl;
        if(!subK2K1.unique())
        {
            std::cout << "SubK2K1 is not unique!" << std::endl;
        }
        subK2K1.reset();
        cout << "K3: subK2K1 reset(ted)" << endl;
        print();
        unionK1.reset();
        cout << "K3: unionK1 reset(ted)" << endl;
        subK4K1.reset();
        cout << "K3: End ~~~~~~~~~~~~~~~~~" << endl;
    }
};

int main()
{
    omp_set_num_threads(omp_get_num_procs());
    cout << "Number of threads (= number of cores): " << omp_get_num_procs() << std::endl;
    {
        std::shared_ptr<Namespace> ns1 = std::shared_ptr<Namespace>(new Namespace());
        ns1->setName("Ns1");
        std::shared_ptr<Namespace> ns2 = std::shared_ptr<Namespace>(new Namespace());
        ns2->setName("Ns2");
        std::shared_ptr<PackageableElement> pe = std::shared_ptr<PackageableElement>(new PackageableElement);
        pe->setName("pe");
        ns1->importedMember->add(pe);
        ns1->ownedMember->add(ns2);

        std::cout << std::endl << "Iterating through all ownedMembers:" << std::endl;
        for (typename std::vector<std::shared_ptr<NamedElement> >::const_iterator it = ns1->ownedMember->begin();
             it != ns1->ownedMember->end();
             ++it)
        {
            std::shared_ptr<NamedElement> ne = dynamic_pointer_cast<NamedElement>(*it);
            if(ne)
            {
                std::cout << "Calling \"print\" method of the NamedElement - ";
                ne->print();
                std::cout << std::endl;
            }
            else
            {
                std::cout << "The given element is not a NamedElement" << std::endl;
            }
        }

        std::cout << std::endl << "Iterating through all ownedElements:" << std::endl;
        std::shared_ptr<Union<Element>> oe = ns1->ownedElement;
        std::vector<std::shared_ptr<Element> >::const_iterator ite = oe->begin();
        for (typename std::vector<std::shared_ptr<Element> >::const_iterator it = oe->begin(); it != oe->end();
             ++it)
        {
            std::shared_ptr<NamedElement> ne = dynamic_pointer_cast<NamedElement>(*it);
            if(ne)
            {
                std::cout << "Calling \"print\" method of the NamedElement - ";
                ne->print();
                std::cout << std::endl;
            }
            else
            {
                std::cout << "The given element is not a NamedElement" << std::endl;
            }
        }

        std::cout << std::endl << "Iterating through all members:" << std::endl;
        for (typename std::vector<std::shared_ptr<NamedElement> >::const_iterator it = ns1->member->begin(); it !=
                                                                                                             ns1->member->end();
             ++it)
        {
            std::cout << "Calling \"print\" method of the NamedElement - ";
            (*it)->print();
            std::cout << std::endl;
        }
        std::cout << std::endl << "Cleaning up..." << std::endl;
    }

    std::cout << "Test 1 ended." << std::endl;

    std::cout << std::endl << "Test 2" << std::endl;
    K3 *k3 = new K3();
    k3->print();
    delete k3;
    std::cout << "Test 2 ended." << std::endl;

    return 0;

}

