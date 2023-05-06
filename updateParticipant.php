<?php

include '../controller/participantC.php';

$error = "";

// create participant
$participant = null;

// create an instance of the controller
$participantC = new participantC();
if (
    isset($_POST["idparticipant"]) &&
    isset($_POST["nom"]) &&
    isset($_POST["prenom"]) &&
    isset($_POST["telephone"]) &&
    isset($_POST["mail"])  
   
) {
    if (
        !empty($_POST["idparticipant"]) &&
        !empty($_POST['nom']) &&
        !empty($_POST["prenom"]) &&
        !empty($_POST["telephone"]) &&
        !empty($_POST["mail"]) 
         
    ) {
        $participant = new participant(
            $_POST['idparticipant'],
            $_POST['nom'],
            $_POST['prenom'],
            $_POST['telephone'],
            $_POST['mail']
            

        );
        $participantC->updateparticipant($participant, $_POST["idparticipant"]);
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
</head>


<style>
       



       html,
body {
	height: 100%;
}

body {
	margin: 0;
	background: linear-gradient(45deg, #49a09d, #5f2c82);
	font-family: sans-serif;
	font-weight: 100;
}

.container {
	position: absolute;
	top: 50%;
	left: 50%;
	transform: translate(-50%, -50%);
}

table {
	width: 800px;
	border-collapse: collapse;
	overflow: hidden;
	box-shadow: 0 0 20px rgba(0,0,0,0.1);
}

th,
td {
	padding: 15px;
	background-color: rgba(255,255,255,0.2);
	color: #fff;
}

th {
	text-align: left;
}

thead {
	th {
		background-color: #55608f;
	}
}

tbody {
	tr {
		&:hover {
			background-color: rgba(255,255,255,0.3);
		}
	}
	td {
		position: relative;
		&:hover {
			&:before {
				content: "";
				position: absolute;
				left: 0;
				right: 0;
				top: -9999px;
				bottom: -9999px;
				background-color: rgba(255,255,255,0.2);
				z-index: -1;
			}
		}
	}
}








      </style>

<style>
        body {
          background-mail: url("mails/cinek.jpg");
          background-position: center;
          background-size: cover;
        }
      </style>

<body>
    <button><a href="Listparticipant.php">Back to list</a></button>
    <hr>

    <div id="error">
        <?php echo $error; ?>
    </div>

    <?php
    if (isset($_POST['idparticipant'])) {
        $participant = $participantC->showparticipant($_POST['idparticipant']);

    ?>

        <form action="" method="POST">
            <table border="1" align="center">
                <tr>
                    <td>
                        <label for="idparticipant">Id participant:
                        </label>
                    </td>
                    <td><input type="text" name="idparticipant" id="idparticipant" value="<?php echo $participant['idparticipant']; ?>"></td>
                </tr>
                <tr>
                    <td>
                        <label for="nom">nom:
                        </label>
                    </td>
                    <td><input type="text" name="nom" id="nom" value="<?php echo $participant['nom']; ?>"></td>
                </tr>
                <tr>
                    <td>
                        <label for="prenom">prenom:
                        </label>
                    </td>
                    <td><input type="text" name="prenom" id="prenom" value="<?php echo $participant['prenom']; ?>"></td>
                </tr>
                <tr>
                    <td>
                        <label for="telephone">telephone:
                        </label>
                    </td>
                    <td>
                        <input type="text" name="telephone" value="<?php echo $participant['telephone']; ?>" id="telephone">
                    </td>
                </tr>
                
              
                <tr>
                    <td>
                        <label for="mail">mail:
                        </label>
                    </td>
                    <td>
                        <input type="text" name="mail" value="<?php echo $participant['mail']; ?>" id="mail">
                    </td>
                </tr>
                
              
              
              
              
              
              
                <tr>
                    <td></td>
                    <td>
                        <input type="submit" value="Update">
                    </td>
                    <td>
                        <input type="reset" value="Reset">
                    </td>
                </tr>
            </table>
        </form>
    <?php
    }
    ?>
</body>

</html>