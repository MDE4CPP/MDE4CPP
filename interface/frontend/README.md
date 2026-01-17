# MDE4CPP Build Service Frontend

A modern web interface for the MDE4CPP Build Service.

## Features

- Drag-and-drop file upload
- Real-time build status tracking
- Progress indicators
- Download DLLs and executables
- Build logs viewing

## Setup

### Option 1: Serve with Python (recommended for testing)

```bash
cd interface/frontend
python -m http.server 3000
```

Then open `http://localhost:3000` in your browser.

### Option 2: Serve with Node.js

```bash
cd interface/frontend
npx http-server -p 3000
```

### Option 3: Use a web server

Copy the files to any web server (Apache, Nginx, etc.)

## Configuration

Update the API URL in `js/api.js` if your backend runs on a different host/port:

```javascript
const API_BASE_URL = 'http://localhost:8000/api/v1';
```

## CORS Configuration

Make sure your backend CORS settings allow your frontend origin. Update `interface/backend/.env`:

```
CORS_ORIGIN=http://localhost:3000,http://localhost:8080
```

Or update `interface/backend/src/config/index.js` to allow all origins for development:

```javascript
cors: {
    origin: '*' // Only for development!
}
```

## Usage

1. Open the frontend in your browser
2. Drag and drop a `.ecore` or `.uml` file onto the upload area
3. Wait for the build to complete (2-5 minutes typically)
4. Download your compiled DLLs and executables

## Browser Support

Modern browsers with ES6+ support:
- Chrome 60+
- Firefox 60+
- Safari 12+
- Edge 79+
