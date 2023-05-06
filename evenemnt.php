

<?php
include '../controller/EvenementC.php';
$evenementC = new evenementC();
$list = $evenementC->listevenement();
?>













<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../View/css/bootstrap.min.css">
    <link href="../View/css/site.css" rel="stylesheet">
    <link href="../View/css/Website.styles.css" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Roboto:300,400,500,700&amp;display=swap" rel="stylesheet">
    <link href="../View/css/MudBlazor.min.css" rel="stylesheet">
    <link href="../View/css/style_login&inscription.css" rel="stylesheet">
    <link rel="stylesheet" href="https://maxst.icons8.com/vue-static/landings/line-awesome/line-awesome/1.3.0/css/line-awesome.min.css"> 
    <link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'> 
    <link rel="stylesheet" href="../View/node_modules/open-iconic-bootstrap.min.css">
    <title>Document</title>
</head>
<body>
 
 



    <header style="background-color: rgb(80, 40, 160);" class="mud-appbar mud-appbar-fixed-top mud-elevation-0 mud-theme-inherit">
        <!--TOOLBAR!-->
        <div onclick="showorhide()" class="mud-toolbar mud-toolbar-gutters mud-toolbar-appbar">
            <!--Contenu de navbar!-->
            <button onclick="showorhide()" type="button" class="mud-button-root mud-icon-button mud-inherit-text hover:mud-inherit-hover mud-ripple mud-ripple-icon mud-icon-button-edge-start" _bl_ccd8e5ff-418e-451d-b3b5-cc3a7a2a5d27="">
            <!--tooblar icon-->
                <span class="mud-icon-button-label">
                <svg class="mud-icon-root mud-svg-icon mud-icon-size-medium" focusable="false" viewBox="0 0 24 24" aria-hidden="true"><!--!-->
                        <path d="M0 0h24v24H0z" fill="none"></path>
                        <path d="M3 18h18v-2H3v2zm0-5h18v-2H3v2zm0-7v2h18V6H3z"></path>
                    </svg></span></button>
                    <!-- LOGO !-->
                    <h1 style="font-size: xx-large;border-radius: 5px;background-color: rgb(247, 242, 242);padding:6px 0px 0px 0px;height: 55px; width: 150px;margin-top: 5px; "><span class="lab la-accusoft" top="20px" style="margin-left: 10px;margin-right:20px;">Artivo</span></h1>
            <!--Accueil!-->
            <a type="button" href="http://127.0.0.1:5500/View/Home.html" class="mud-button-root mud-button mud-button-text mud-button-text-inherit mud-button-text-size-medium mud-ripple">
                <span class="mud-button-label"><i class="bx bxs-home"></i>Accueil</span></a><!--!-->
            <!--Shop!-->
            <a type="button" href="http://localhost/workshop5/view/listEvenement.php"  class="mud-button-root mud-button mud-button-text mud-button-text-inherit mud-button-text-size-medium mud-ripple">
                <span class="mud-button-label"><i class="bx bxs-shopping-bags"></i>liste</span></a><!--!-->
            <!--Event!-->
            <a type="button" href="http://127.0.0.1:5500/View/evenemnt.html" class="mud-button-root mud-button mud-button-text mud-button-text-inherit mud-button-text-size-medium mud-ripple">
                <span class="mud-button-label"><i class="bx bxs-calendar-event"></i>Evénement</span></a><!--!-->
            <!--Contact!-->
            <a type="button" href="contact" class="mud-button-root mud-button mud-button-text mud-button-text-inherit mud-button-text-size-medium mud-ripple">
                <span class="mud-button-label"><i class="bx bxs-phone"></i>Contact</span></a>
            <!--ENA hamdi! div loula postion w div thenia 5li9ti w h6 ismi-->
            <div class="flex-grow-1"></div>
            <div class="mud-avatar mud-avatar-medium mud-avatar-filled mud-avatar-filled-default mud-elevation-0"><img src="../View/images/hamdi.jpg" class="mud-avatar-img"></div>
            <h6 class="mud-typography mud-typography-subtitle1 pl-3"><font color="#fff"><b>ghassen khelifi</b></font></h6>
            <!--DARK/light Mode!-->
            <button onclick="showorhide()" type="button" class="mud-button-root mud-button mud-button-text mud-button-text-secondary mud-button-text-size-medium mud-ripple">
                <span class="mud-button-label">
                    <span class="mud-button-icon-end mud-button-icon-size-medium">
                        <svg class="mud-icon-root mud-svg-icon mud-icon-size-medium" focusable="false" viewBox="0 0 24 24" aria-hidden="true">
                            <path d="M0 0h24v24H0z" fill="none"></path>
                            <path d="M6.76 4.84l-1.8-1.79-1.41 1.41 1.79 1.79 1.42-1.41zM4 10.5H1v2h3v-2zm9-9.95h-2V3.5h2V.55zm7.45 3.91l-1.41-1.41-1.79 1.79 1.41 1.41 1.79-1.79zm-3.21 13.7l1.79 1.8 1.41-1.41-1.8-1.79-1.4 1.4zM20 10.5v2h3v-2h-3zm-8-5c-3.31 0-6 2.69-6 6s2.69 6 6 6 6-2.69 6-6-2.69-6-6-6zm-1 16.95h2V19.5h-2v2.95zm-7.45-3.91l1.41 1.41 1.79-1.8-1.41-1.41-1.79 1.8z">
                            </path>
                        </svg></span></span></button>
        </div>
    </header><br><br><br><br>


















 
 
    <style>
        body {
          background-image: url("images/cinedaz.jpg");
          background-position: center;
          background-size: cover;
        }
      </style>
 
 
 
 
 
 
 
    
    <br><br><br>
   

   
    
    <div class="mud-grid mud-grid-spacing-xs-4 justify-center"><!--!-->


    <?php
   foreach ($list as $evenementC) {
?> 


<div class="mud-grid-item"><!--!--><!--!-->
                    <div class="mud-paper mud-elevation-0"><!--!--><!--!-->
                        <div class="mud-grid mud-grid-spacing-xs-3 justify-center"><!--!-->
                            <div class="mud-grid-item"><!--!-->
                                <div class="mud-avatar mud-avatar-medium mud-avatar-filled mud-avatar-filled-default mud-elevation-0"><img src="../View/images/hamdi.jpg" class="mud-avatar-img">
                                </div>
                            </div><!--!-->

                            <!--!ili ta7t hoodys-->
                            <div class="mud-grid-item"><!--!-->
                                <p class="mud-typography mud-typography-body1">Artivo 9 TN</p><!--!-->
                                <!--!-->
                                <div class="mud-grid-item"><!--!-->
                                    <p class="mud-typography mud-typography-body2">13.4k Followers</p>
                                </div>
                            </div><!--!-->

                            <!--!-->
                            <div class="mud-grid-item pl-15"><!--!--><!--!-->
                                <div class="mud-input-control mud-input-control-boolean-input">
                                    <div class="mud-input-control-input-container"><label class="mud-checkbox mud-ltr" id="checkbox31de0caa"><span tabindex="0" class="mud-button-root mud-icon-button mud-secondary-text hover:mud-secondary-hover mud-ripple mud-ripple-checkbox"><input tabindex="-1" type="checkbox" class="mud-checkbox-input"><!--!-->
                                                <!--!--><svg class="mud-icon-root mud-svg-icon mud-icon-size-medium" focusable="false" viewBox="0 0 24 24" aria-hidden="true"><!--!-->
                                                    <path d="M0 0h24v24H0z" fill="none"></path>
                                                    <path d="M16.5 3c-1.74 0-3.41.81-4.5 2.09C10.91 3.81 9.24 3 7.5 3 4.42 3 2 5.42 2 8.5c0 3.78 3.4 6.86 8.55 11.54L12 21.35l1.45-1.32C18.6 15.36 22 12.28 22 8.5 22 5.42 19.58 3 16.5 3zm-4.4 15.55l-.1.1-.1-.1C7.14 14.24 4 11.39 4 8.5 4 6.5 5.5 5 7.5 5c1.54 0 3.04.99 3.57 2.36h1.87C13.46 5.99 14.96 5 16.5 5c2 0 3.5 1.5 3.5 3.5 0 2.89-3.14 5.74-7.9 10.05z">
                                                    </path>
                                                </svg></span></label></div>
                                </div>
                            </div>
                        </div><!--!-->

                        <div class="purpleDivider"></div>
                      <!--!--><img src="images/<?= $evenementC['image'];?>" class="mud-image object-fill object-center" style="height: 22em;"><!--!-->
                        <div class="purpleDivider"></div>

                        <!--!--><!--!-->
                        <div class="mud-grid mud-grid-spacing-xs-3 justify-center py-2 px-6"><!--!-->
                            <div class="mud-grid-item"><!--!-->
                            <h6 class="mud-typography mud-typography-subtitle1"> <?= $evenementC['titre'];?> </h6><!--!-->
                                <!--!-->
                                <h6 class="mud-typography mud-typography-h6"> <?= $evenementC['prix'];?> DT</h6>
                            </div><!--!-->

                            <!--!--><!--!-->
                            <div class="flex-grow-1"></div><!--!-->

                            <!--!-->
                            <div class="mud-grid-item"><!--!--><span tabindex="0" class="mud-rating-root"><!--!--><!--!--><span class="mud-rating-item mud-ripple mud-ripple-icon yellow-text.text-darken-3 mud-readonly"><!--!--><svg class="mud-icon-root mud-svg-icon mud-icon-size-small" focusable="false" viewBox="0 0 24 24" aria-hidden="true"><!--!-->
                                            <path d="M0 0h24v24H0z" fill="none"></path>
                                            <path d="M0 0h24v24H0z" fill="none"></path>
                                            <path d="M12 17.27 18.18 21l-1.64-7.03L22 9.24l-7.19-.61L12 2 9.19 8.63 2 9.24l5.46 4.73L5.82 21z">
                                            </path>
                                        </svg></span><!--!--><span class="mud-rating-item mud-ripple mud-ripple-icon yellow-text.text-darken-3 mud-readonly"><!--!--><svg class="mud-icon-root mud-svg-icon mud-icon-size-small" focusable="false" viewBox="0 0 24 24" aria-hidden="true"><!--!-->
                                            <path d="M0 0h24v24H0z" fill="none"></path>
                                            <path d="M0 0h24v24H0z" fill="none"></path>
                                            <path d="M12 17.27 18.18 21l-1.64-7.03L22 9.24l-7.19-.61L12 2 9.19 8.63 2 9.24l5.46 4.73L5.82 21z">
                                            </path>
                                        </svg></span><!--!--><span class="mud-rating-item mud-ripple mud-ripple-icon yellow-text.text-darken-3 mud-readonly"><!--!--><svg class="mud-icon-root mud-svg-icon mud-icon-size-small" focusable="false" viewBox="0 0 24 24" aria-hidden="true"><!--!-->
                                            <path d="M0 0h24v24H0z" fill="none"></path>
                                            <path d="M0 0h24v24H0z" fill="none"></path>
                                            <path d="M12 17.27 18.18 21l-1.64-7.03L22 9.24l-7.19-.61L12 2 9.19 8.63 2 9.24l5.46 4.73L5.82 21z">
                                            </path>
                                        </svg></span><!--!--><span class="mud-rating-item mud-ripple mud-ripple-icon yellow-text.text-darken-3 mud-readonly"><!--!--><svg class="mud-icon-root mud-svg-icon mud-icon-size-small" focusable="false" viewBox="0 0 24 24" aria-hidden="true"><!--!-->
                                            <path d="M0 0h24v24H0z" fill="none"></path>
                                            <path d="M0 0h24v24H0z" fill="none"></path>
                                            <path d="M12 17.27 18.18 21l-1.64-7.03L22 9.24l-7.19-.61L12 2 9.19 8.63 2 9.24l5.46 4.73L5.82 21z">
                                            </path>
                                        </svg></span><!--!--><span class="mud-rating-item mud-ripple mud-ripple-icon yellow-text.text-darken-3 mud-readonly"><!--!--><svg class="mud-icon-root mud-svg-icon mud-icon-size-small" focusable="false" viewBox="0 0 24 24" aria-hidden="true"><!--!-->
                                            <path d="M0 0h24v24H0z" fill="none"></path>
                                            <path d="M22 9.24l-7.19-.62L12 2 9.19 8.63 2 9.24l5.46 4.73L5.82 21 12 17.27 18.18 21l-1.63-7.03L22 9.24zM12 15.4l-3.76 2.27 1-4.28-3.32-2.88 4.38-.38L12 6.1l1.71 4.04 4.38.38-3.32 2.88 1 4.28L12 15.4z">
                                            </path>
                                        </svg></span></span><!--!-->
                                <!--!-->
                                <div class="mud-grid-item pl-2 pt-2"><!--!--><!--!--><a type="button" href="product/68" class="mud-button-root mud-button mud-button-outlined mud-button-outlined-primary mud-button-outlined-size-medium mud-ripple mud-button-disable-elevation" _bl_2df17a15-981c-4261-ae52-8eb7d49eaa60=""><span class="mud-button-label"><span class="mud-button-icon-start mud-button-icon-size-medium"><!--!--><svg class="mud-icon-root mud-svg-icon mud-icon-size-medium" focusable="false" viewBox="0 0 24 24" aria-hidden="true"><!--!-->
                                                    <path d="M0 0h24v24H0z" fill="none"></path>
                                                    <path d="M7 18c-1.1 0-1.99.9-1.99 2S5.9 22 7 22s2-.9 2-2-.9-2-2-2zM1 2v2h2l3.6 7.59-1.35 2.45c-.16.28-.25.61-.25.96 0 1.1.9 2 2 2h12v-2H7.42c-.14 0-.25-.11-.25-.25l.03-.12.9-1.63h7.45c.75 0 1.41-.41 1.75-1.03l3.58-6.49c.08-.14.12-.31.12-.48 0-.55-.45-1-1-1H5.21l-.94-2H1zm16 16c-1.1 0-1.99.9-1.99 2s.89 2 1.99 2 2-.9 2-2-.9-2-2-2z">
                                                    </path>
                                                </svg></span>Achtez</span></a></div>
                            </div>
                        </div>
                    </div>
                </div>


                

        <?php
         }
          ?> 



<center>

<div>
<br>
<br>

                  <form action="" method="GET" >
            <label for="idevenement">Filtrer par ID de evenement:</label>
            <input type="text" id="idevenement" name="idevenement">
            <input type="submit" value="Filtrer">
            </form>
                <?php 
            $dsn = "mysql:host=localhost;dbname=atelierphp";
            $username = "root";
            $password = "";
            try {
                $conn = new PDO($dsn, $username, $password);
                $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                // Filter by idevenement if set in query string
                if(isset($_GET['idevenement']) && $_GET['idevenement'] !== ''){
                    $stmt = $conn->prepare("SELECT * FROM evenement WHERE idevenement = :idevenement");
                    $stmt->bindParam(':idevenement', $_GET['idevenement']);
                    $stmt->execute();
                }
                else{
                    $stmt = $conn->query("SELECT * FROM evenement");
                }
                
                $result = $stmt->fetchAll(PDO::FETCH_ASSOC);
                foreach ($result as $row) {
            ?>
                    <div class="col-md-6" align="center">
                        <div class="products-single fix" align="center">
                            <div class="box-img-hover" align="center">
                                <div class="why-text" align="center">
                                    
                                    <h5><?php echo $row["idevenement"]; ?></h5>
                                    
                                    
                                    <h1><strong><?php echo $row['titre']; ?></strong></h1>
                                
                                    <p><?php echo $row['description']; ?></p>
                                    <p><?php echo $row['prix']; ?></p>
                                    
                                    
                                   <p> <img src="images/<?php echo $row['image']; ?>"> </p>
                                    
                                    <p><a href="forma.php" class="btn hvr-hover"></a></p>
                                </div>
                            </div>
                        </div>
                    </div>
            <?php
                }
            } catch (PDOException $e) {
                echo "Connection failed: " . $e->getMessage();
            }
            ?> 
</center>

</div>

<form method="post" action="bot.php" align="center">
        <input type="submit" name="bot" value="Communiquer avec Bot">
    </form>
 
</div>

<br>
<br>
<br>

<form action="PHPMailer/index.php" align="center">
  <label for="reclamation">Réclamation:</label>
  <input type="text" name="reclamation" id="reclamation">
  <input type="submit">
</form>

<br>
<br>
<br>


              <iframe class="position-relative rounded w-100 h-100-left"
                src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d3193.650616427098!2d10.189367415255984!3d36.89928778068462!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x12e2cb7454c6ed51%3A0x683b3ab5565cd357!2sESPRIT!5e0!3m2!1sen!2stn!4v1656489344182!5m2!1sen!2stn"
                frameborder="0" allowfullscreen="" aria-hidden="false" tabindex="0" style="filter: grayscale(100%) invert(92%) contrast(83%); border: 0;"></iframe>
          



</body>
</html>


















