function radioCheck(radio) {
    const uno = document.getElementById("uno-grados-div");
    const due = document.getElementById("due-grados-div");
    const tre = document.getElementById("tre-grados-div");

    if (radio == "1") {
        uno.className = 'grados-div on';
        due.className = 'grados-div off';
        tre.className = 'grados-div off';
        console.log("1");
    } else
    if (radio == "2") {
        uno.className = 'grados-div off';
        due.className = 'grados-div on';
        tre.className = 'grados-div off';
        console.log("2");
    } else
    if (radio == "3") {
        uno.className = 'grados-div off';
        due.className = 'grados-div off';
        tre.className = 'grados-div on';
        console.log("3")
    } else {
        alert("something go wrong");
    }
}