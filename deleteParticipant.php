<?php
include '../controller/participantC.php';
$participantC = new participantC();
$participantC->deleteparticipant($_GET["idparticipant"]);
header('Location:Listparticipant.php');
