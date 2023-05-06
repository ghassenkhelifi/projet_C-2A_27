<?php

include '../controller/participantC.php';

$error = "";

// create participant
$participant = null;

// create an instance of the controller
$participantC = new participantC();
if (
    isset($_POST["nom"]) &&
    isset($_POST["prenom"]) &&
    isset($_POST["telephone"])&&
    isset($_POST["mail"]) 
    
) {
    if (
        !empty($_POST['nom']) &&
        !empty($_POST["prenom"]) &&
        !empty($_POST["telephone"])&&
        !empty($_POST["mail"])  
       
    ) {
        $participant = new participant(
            null,
            $_POST['nom'],
            $_POST['prenom'],
            $_POST['telephone'],
            $_POST['mail']
           
        );
        $participantC->addparticipant($participant);
        header('Location:Listparticipant.php');
    } else
        $error = "Missing information";
}








?>



<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Display</title>



    <style>
        body {
          background-mail: url("mails/cinekgh.jpg");
          background-position: center;
          background-size: cover;
        }
      </style>




</head>

<body>
   
<script src="controle saisie.js"></script>

    <a href="Listparticipant.php">Back to list </a>
    <hr>

   



  <form action="" method="POST" >
    
   
        <table border="1" align="center">

           
    
    
             <tr>
                <td>
                    <label for="nom">nom:
                    </label>
                </td>
                <td><input type="text" name="nom" id="nom" placeholder="Your Name" onkeyup="saisie()">  <label id="error"></label> </td>
               
            
            
            </tr>



            
           
            <tr>
                <td>
                    <label for="prenom">prenom:
                    </label>
                </td>
                <td><input type="text" name="prenom" id="prenom" placeholder="Your Name"  onkeyup="saisie()">   <label id="error1"></label>                 </td>
               
            </tr>
           
            <tr>
                <td>
                    <label for="telephone">telephone:
                    </label>
                </td>
                <td>
                    <input type="text" name="telephone" id="telephone" placeholder="Your Name"  onkeyup="saisie()">          <label id="error2"></label>             </td>
                
            </tr>

            <tr>
                <td>
                    <label for="mail">mail:
                    </label>
                </td>
                <td>
                    <input type="text" name="mail" id="mail">
                </td>
            </tr>

    
            
            <tr align="center">
                <td>
                    <input type="submit" value="Save">
                </td>
                <td>
                    <input type="reset" value="Reset">
                </td>
            </tr>
        </table>
    </form>




  



















<form id="form" class="form" method="post" action="">
          <div class="row">

           <!--div class="row form-group">
             <div class="col-md-6 mb-3 mb-md-0">
               <label class="text-black" for="idclient">Id Client</label> 
               <input type="number" class="" name="idclient" id="idclient" placeholder="Please enter your id"   required title="le champ ne doit contenir que des nombres >
               <div class="validate"></div>
             </div-->

             <div class="col-md-6">  
             <label class="text-black" for="Reference">Id Client</label>       
              <input type="number" class="form-control" name="idclient" id="idclient" placeholder="idclient" data-rule="minlen:4" data-msg="Please enter at least 4 chars" onkeyup="idclientValidation()" required >
              <div>
              <div class="validate"></div>
             <p style="color :red" id="idclientr"></p>
             </div>
             </div>

             <div class="col-md-6">
               <label class="text-black" for="Reference">Reference</label> 
               <input type="number" class="form-control" name="reference" id="reference" placeholder="Reference" data-rule="reference" data-msg="Entrez Reference"  onkeyup="referenceValidation()">
               <div class="validate"></div>
               <p style="color: red" id="referenceEr"></p>
             </div>
             </div>

           <div class="row form-group">
             <div class="col-md-12">
               <label class="text-black" for="message">Message</label> 
               <textarea name="message" id="message" cols="30" rows="7" class="form-control" placeholder="Write your notes or questions here..."></textarea>
               <div class="validate"></div>
               <p style="color: red" id="passEr"></p>
             </div>
           </div>
<br>  </br>
           <div class="row form-group">
             
             <div class="col-md-12">
               <label class="text-black" for="email">Email</label> 
               <input type="text" class="form-control" name="email" id="email" placeholder="Entrez votre adresse email"  data-msg="Please enter a valid email">
               <span id="text"></span>
             
             </div>
           </div>

           <div class="col-lg-4 col-md-6 form-group mt-3">
             <input type="date" class="form-control" name="dob" id="dob" placeholder="dob" data-rule="minlen:4" data-msg="Please enter at least 4 chars">
             <div class="validate"></div>
           </div>
         <div class="mb-3">
           <div class="error-message"></div>

  
    <div class="center">
        <h1 id="captchaHeading">Captcha</h1>
        <div id="captchaBackground">
            <canvas id="captcha">captcha text</canvas>
            <input id="textBox" type="text" name="text">
            <div id="buttons">
                
                <button id="refreshButton" type="submit">Refresh</button>
            </div>
            <span id="output"></span>
        </div>
    </div>

         </div>
         <br> </br>
         <div class="text-center">
          <button type="submit" id="submitButton"  class="btn btn-primary btn-block" value="Submit"  onclick="referenceValidation()">Send Message</button></div>
         <div id="heure"></div>
       </form>   <p style="color: red" id="erreur"></p>








</body>

</html>