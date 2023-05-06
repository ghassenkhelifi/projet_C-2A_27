<?php
include '../controller/participantC.php';
$participantC = new participantC();
$list = $participantC->listparticipant();
?>
<html>






  
   
    
   





<head>

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
<a href="http://localhost/workshop5/view/evenemnt.php">Back ADMIN </a>
    <center>
        <h1>List of participants</h1>
        <h2>
            <a href="addparticipant.php">Add participant</a>
        </h2>
    </center>
    <table border="1" align="center" width="70%">
        <tr>
            <th>Id participant</th>
            <th>nom</th>
            <th>prenom</th>
            <th>telephone</th>
            <th>mail</th>
           
            <th>Update</th>
            <th>Delete</th>
        </tr>
        <?php
        foreach ($list as $participant) {
        ?>
            <tr>
                <td><?= $participant['idparticipant']; ?></td>
                <td><?= $participant['nom']; ?></td>
                <td><?= $participant['prenom']; ?></td>
                <td><?= $participant['telephone']; ?></td>
                <td><?= $participant['mail']; ?></td>
                

                
                
                <td align="center">
                    <form method="POST" action="updateparticipant.php">
                        <input type="submit" name="update" value="Update">
                        <input type="hidden" value=<?PHP echo $participant['idparticipant']; ?> name="idparticipant">
                    </form>
                </td>
                <td>
                    <a href="deleteparticipant.php?idparticipant=<?php echo $participant['idparticipant']; ?>">Delete</a>
                </td>
            </tr>
        <?php
        }
        ?>
    </table>
</body>

</html>