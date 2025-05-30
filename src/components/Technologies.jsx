import React from 'react';
import './Technologies.css';

const technologies = [
    { name: 'HTML', level: 'Advanced', link: 'https://developer.mozilla.org/es/docs/Web/HTML' },
    { name: 'CSS', level: 'Advanced', link: 'https://developer.mozilla.org/es/docs/Web/CSS' },
    { name: 'JavaScript', level: 'Intermediate', link: 'https://developer.mozilla.org/es/docs/Web/JavaScript' },
    { name: 'React', level: 'Beginner', link: 'https://es.react.dev/' },
    { name: 'Java', level: 'Intermediate', link: 'https://www.java.com/es/' },
    { name: 'Python', level: 'Intermediate', link: 'https://www.python.org/' },
    { name: 'Git & GitHub', level: 'Advanced', link: 'https://git-scm.com/' },
    { name: 'SQL', level: 'Intermediate', link: 'https://www.mysql.com/' },
];

const Technologies = () => {
    return (
        <aside id="technologies" className="technologies">
            <h2 className="technologies__title">Technologies</h2>
            {technologies.map((tech, index) => (
                <div className="card" key={index} data-link={tech.link} onClick={() => window.open(tech.link, '_blank')}>
                    <div className="card-inner">
                        <div className="card-front">
                            <h3>{tech.name}</h3>
                        </div>
                        <div className="card-back">
                            <h3>{tech.level}</h3>
                        </div>
                    </div>
                </div>
            ))}
        </aside>
    );
};

export default Technologies;