import Technologies from "./Technologies";
import Projects from "./Projects";
import './Portfolio.css';	

const Portfolio = () => {
    return (
        <section className="portfolio" id="portfolio">
            <Projects />
            <Technologies />
        </section>
    );
};

export default Portfolio;