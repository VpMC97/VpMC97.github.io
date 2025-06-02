export const initScrollAnimations = () => {
    const observerOptions = {
        root: null,
        rootMargin: '0px',
        threshold: Array.from({ length: 100 }, (_, i) => i / 100) // Create 100 threshold points for smooth transition
    };

    const handleIntersect = (entries) => {
        entries.forEach(entry => {
            const element = entry.target;
            const ratio = entry.intersectionRatio;
            
            // Calculate opacity based on scroll position
            const opacity = Math.min(ratio * 2, 1); // Double the ratio to make elements appear faster
            element.style.opacity = opacity;

            // Calculate transform based on scroll position
            const translateY = (1 - ratio) * 30; // Max 30px transform
            if (element.classList.contains('scroll-reveal')) {
                element.style.transform = `translateY(${translateY}px)`;
            } else if (element.classList.contains('scroll-reveal-left')) {
                element.style.transform = `translateX(${-translateY}px)`;
            } else if (element.classList.contains('scroll-reveal-right')) {
                element.style.transform = `translateX(${translateY}px)`;
            }
        });
    };

    const observer = new IntersectionObserver(handleIntersect, observerOptions);

    const animatedElements = document.querySelectorAll('.scroll-reveal, .scroll-reveal-left, .scroll-reveal-right');
    animatedElements.forEach(el => {
        observer.observe(el);
        el.style.opacity = '0';
        el.style.transition = 'opacity 0.4s ease, transform 0.4s ease';
    });
}; 