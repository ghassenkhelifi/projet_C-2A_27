

const logregBox = document.querySelector('.logreg-box');
const loginLink = document.querySelector('.login-link');
const registerLink = document.querySelector('.register-link');
registerLink.addEventListener('click', () => {logregBox.classList.add('active');});
loginLink.addEventListener('click', () => {logregBox.classList.remove('active');});

/*function passValidation(){
    var pass=document.getElementById("pass").value;
    var a=document.getElementById("passc").value;
    if(pass!=a) alert("la confirmation est echouée!!!");
}*/
class formulaire{constructor (){
    this.nom=document.querySelector("#nom").value;
    this.prenom=document.querySelector("#prenom").value;
    this.tel=document.querySelector("#numtel").value;
    this.motpass=document.querySelector("#pass").value;
    this.cpass=document.querySelector("#passc").value;
    this.addresse=document.querySelector("#kifeh").value;
}}
function verif(){
const formulairev =new formulaire();
/*if(/^[A-Za-z]{3,20}$/.test(formulairev.nom))
document.getElementById("resn").innerHTML="<span style='color: green;font-size: xx-large;'><i class='bx bx-check'></i></span";
else
document.getElementById("resn").innerHTML = "<span style='color: red;'>le nom doit compter au min 3 caracteres.</span>";
*/if(/^[A-Za-z]{4,20}$/.test(formulairev.prenom))
document.getElementById("resp").innerHTML="<span style='color: green;font-size: xx-large;'><i class='bx bx-check'></i></span>";
else
document.getElementById("resp").innerHTML = "<span style='color: red;'>le prenom doit compter au min 4 caracteres.</span>";
if(/^[0-9]{8,8}$/.test(formulairev.tel))
document.getElementById("restel").innerHTML="<span style='color: green;font-size: xx-large;'><i class='bx bx-check'></i></span";
else
document.getElementById("restel").innerHTML = "<span style='color: red;'>Numéro de téléphone est composé de 8 chiffres.</span>";
if(formulairev.motpass.match(( /[0-9]/))&&formulairev.motpass.match(( /[a-z]/))&&formulairev.motpass.match(( /[A-Z]/)))
document.getElementById("resmp").innerHTML="<span style='color: green;font-size: xx-large;'><i class='bx bx-check'></i></span";
else
document.getElementById("resmp").innerHTML = "<span style='color: red;'>Motpass faible.</span>";
if(formulairev.motpass==formulairev.cpass)
document.getElementById("resmpc").innerHTML="<span style='color: green;font-size: xx-large;'><i class='bx bx-check'></i></span";
else
document.getElementById("resmpc").innerHTML = "<span style='color: red;'>Le motpass ne correspondent pas.</span>";
if(formulairev.addresse=="")
document.getElementById("res").innerHTML="<br><span style='color: red;'>Veuillez remplir tous les champs.</span>";
else
document.getElementById("res").innerHTML = "<br><span style='color: green;font-size: xx-large;'><i class='bx bx-check'></i></span";
}
function nameValidation(){
const formulairev=new formulaire();
if(/^[A-Za-z]{3,20}$/.test(formulairev.nom))
document.getElementById("resn").innerHTML="<span style='color: green;font-size: xx-large;'><i class='bx bx-check'></i></span>";
else
document.getElementById("resn").innerHTML = "<span style='color: red;'>le nom doit compter au min 3 caracteres.</span>";
}



