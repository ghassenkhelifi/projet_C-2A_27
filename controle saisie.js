function saisie(){
    var titre=document.getElementById("titre").value; 
    var error=document.querySelector("#error");
    var letters = /^[A-Za-z]+$/; // expression régulière pour les lettres seulement

    
    var description=document.getElementById("description").value;
    var error1=document.querySelector("#error1");
   
    
    var prix=document.getElementById("prix").value; 
    var error2=document.querySelector("#error2");
    
    
   
   
    
    

    if (titre.length == 0){
        error.innerHTML="Veuillez saisir votre titre.";
        error.style.color="red";
    }
   
   
   
    else if (!titre.match(letters)){
        error.innerHTML="Veuillez saisir seulement des lettres.";
        error.style.color="red";
   
   
    }
    else
    {
        error.innerHTML="Correct";
        error.style.color="green";
    }
    
    
    if (description.length == 0){
        error1.innerHTML="Veuillez saisir votre description.";
        error1.style.color="red";
    }
    else
    {
        error1.innerHTML="Correct";
        error1.style.color="green";  
    }

    
    if (prix.length == 0){
        error2.innerHTML="Veuillez saisir votre prix";
        error2.style.color="red";
    }
    else
    {
        error2.innerHTML="Correct";
        error2.style.color="green"; 
    } 
    


    var titree = document.getElementById("titre").value;
    var regex = /^[a-zA-Z\s]*$/;
    var error3 = document.querySelector("#error3");
  
    if (titree.trim() === "") {
        error3.innerHTML = "Le titre ne peut pas être vide";
      error3.style.color = "red";
      
    } else if (!regex.test(titre)) {
      error3.innerHTML = "Le titre ne doit contenir que des lettres";
      error3.style.color = "red";
      
    } else {
        error3.innerHTML = "";
      
    }









}



function envoyer(){
    var titre=document.getElementById("titre").value; 
    var prix=document.getElementById("prix").value;
    var description=document.getElementById("description").value; 
   
    if (titre.length==0 || prix.length==0 || description.length==0 )
    alert("completer les champs");
    else
    alert("envoie réussie");
}








