import React from 'react';
import './Projects.css';

const projectsData = [
    {
        title: "Calculator",
        image: "../../src/images/calculator.png",
        description: "Simple calculator made with HTML, CSS and JS",
        link: "https://github.com/VpMC97/calculadora"
    },
    {
        title: "School Web Page",
        image: "src/images/school.png",
        description: "Web Page for a kindergarden school made with HTML, CSS and JS",
        link: "https://github.com/VpMC97/School-Page"
    },
    {
        title: "Neuroscience page",
        image: "./src/images/brain.png",
        description: "Information web about Neuroscience",
        link: "https://github.com/VpMC97/neuroscience-web-page"
    },
    {
        title: "Billing System",
        image: "./src/images/bank.png",
        description: "CRUD for a billing system with Java and SQLServer",
        link: "https://github.com/VpMC97/Billing-System-Java-DB"
    }
];

const Projects = () => {
    return (
        <section className="projects">
            <h2 className="projects__title">Projects</h2>
            {
            projectsData.map((project, index) => (
                <div className="projects__card" key={index}>
                    <div className="project__image-container">
                        <img className="project-image" src={project.image} alt={project.title} />
                    </div>
                    <div className="project__description">
                        <h2 className="project-title">{project.title}</h2>
                        <button className="button" onClick={() => window.open(project.link, "_blank")}>
                            <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth="1.5" stroke="currentColor">
                                <path strokeLinecap="round" strokeLinejoin="round" d="M4.5 12h15m0 0l-6.75-6.75M19.5 12l-6.75 6.75"></path>
                            </svg>
                        </button>
                        <br />
                        <p className="project-subtitle">{project.description}</p>
                    </div>
                </div>
            ))
            }
        </section>
    );
};

export default Projects;