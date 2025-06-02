import React from 'react'
import ReactDOM from 'react-dom/client'
import App from './App.jsx'
import './style.css'
import { initScrollAnimations } from './utils/scrollAnimations'

// Initialize animations as soon as possible
document.addEventListener('DOMContentLoaded', initScrollAnimations);

ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <App />
  </React.StrictMode>,
);

// Re-initialize animations after React hydration
setTimeout(initScrollAnimations, 0);
