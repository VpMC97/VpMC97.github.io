import Technologies from "./Technologies";
import Projects from "./Projects";
import './Portfolio.css';	

const Portfolio = () => {
    return (
        <section className="portfolio" id="portfolio">
            <div className="scroll-reveal">
                <Projects />
            </div>
            <div className="scroll-reveal delay-400">
                <Technologies />
            </div>
        </section>
    );
};

export default Portfolio;