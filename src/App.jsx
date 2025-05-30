
import { useState } from 'react';
import Header from './components/Header';
import Profile from './components/Profile';
import Contact from './components/Contact';
import Footer from './components/Footer';
import Portfolio from './components/Portfolio';
import './App.css';




const App = () => {
    const [state, setState] = useState(false);

    const toggleState = () => {
        setState(!state);
    }
    document.body.className = state ? 'dark' : 'light';

    return (
        <>
            <Header parentMethod={toggleState}/>
            <main className="profile">
                <Profile />
                <Portfolio/>
                <Contact />
            </main>
            <Footer />
        </>
    );
};

export default App;