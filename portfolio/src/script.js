document.querySelectorAll('.projects__card .button').forEach(btn => {
    btn.addEventListener('click', function() {
    const link = this.getAttribute('data-link');
    if (link) {
        window.open(link, '_blank');
    }
    });
});

document.querySelectorAll('.card').forEach(card => {
    card.addEventListener('click', function() {
        const link = this.getAttribute('data-link');
        if (link) {
            window.open(link, '_blank');
        }
    });
});

document.querySelector('.download-button').addEventListener('click', function () {
    const link = document.createElement('a');
    link.href = './pdf/Viviana_Mendez-Resume.pdf';
    link.download = 'Viviana_Mendez-Resume.pdf';
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
});