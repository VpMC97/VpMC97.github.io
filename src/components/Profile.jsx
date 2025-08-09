import React from 'react';
import './Profile.css';

const Profile = () => {
    const downloadResume = () => {
        const link = document.createElement('a');
        link.href = import.meta.env.BASE_URL + 'Viviana_Mendez_Resume.pdf';
        link.download = 'Viviana_Mendez_Resume.pdf';
        document.body.appendChild(link);
        link.click();
        document.body.removeChild(link);
    };

    return (
        <section id="about" className="profile__wrapper">
            <div className="profile__img-container scroll-reveal-left">
                <img src="/images/profile.png" alt="su" className="profile__img" />
            </div>
            <div className="profile__title scroll-reveal">
                <h2 className="profile__title-subtitle">
                    <span>Hi, </span><br />
                    I'm an Information Systems Engineering and Computer Science Student
                </h2>
                <p className="profile__title-nickname">my friends call me <span>Isoft</span></p>
            </div>
            <div className="profile__data-container scroll-reveal-right">
                <div className="profile__data">
                    <h1>Viviana Isapamela Méndez Ché</h1>
                    <br />
                    <p>An aspiring Information Systems Engineering and Computer Science student with a passion for technology and
                    innovation. Proficient in web development, object-oriented programming, databases, and software development.
                    Strong teamwork and problem solving skills developed through academic projects.</p>
                    <br />
                    <p> Interested in leveraging technical expertise and creativity in a challenging internship or entry-level position.
                    Committed to continuous learning, with passion for emerging technologies for improvement in the tech field.</p>
                </div>
                <button className="download-button" onClick={downloadResume}>
                    <div className="docs">
                        <svg viewBox="0 0 24 24" width="20" height="20" stroke="currentColor" strokeWidth="2" fill="none" strokeLinecap="round" strokeLinejoin="round" className="css-i6dzq1">
                            <path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"></path>
                            <polyline points="14 2 14 8 20 8"></polyline>
                            <line x1="16" y1="13" x2="8" y2="13"></line>
                            <line x1="16" y1="17" x2="8" y2="17"></line>
                            <polyline points="10 9 9 9 8 9"></polyline>
                        </svg>
                        Resume
                    </div>
                    <div className="download">
                        <svg viewBox="0 0 24 24" width="24" height="24" stroke="currentColor" strokeWidth="2" fill="none" strokeLinecap="round" strokeLinejoin="round" className="css-i6dzq1">
                            <path d="M21 15v4a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2v-4"></path>
                            <polyline points="7 10 12 15 17 10"></polyline>
                            <line x1="12" y1="15" x2="12" y2="3"></line>
                        </svg>
                    </div>
                </button>
            </div>
        </section>
    );
};

export default Profile;