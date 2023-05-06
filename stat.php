<?php





                try {
                  $dbh = new PDO('mysql:host=localhost;dbname=atelierphp', 'root', '');
                } catch (PDOException $e) {
                  echo 'Connection failed: ' . $e->getMessage();
                }

                $query = "SELECT prix, sum(idevenement) FROM evenement group by prix";
                $res = $dbh->query($query);
                ?>

                <html>
                  <head>
                    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
                    <script type="text/javascript">
                      google.charts.load('current', {'packages':['corechart']});
                      google.charts.setOnLoadCallback(drawChart);

                      function drawChart() {
                        var data = google.visualization.arrayToDataTable([
                          ['prix', 'idevenement'],
                          <?php 
                          while($row=$res->fetch(PDO::FETCH_ASSOC)) {
                            echo "['".$row['prix']."',".$row['sum(idevenement)']."],";
                          }
                          ?>
                        ]);

                        var options = {
                          title: 'Statistiques des evenements',
                          
                          
                        };

                        var chart = new google.visualization.PieChart(document.getElementById('piechart'));

                        chart.draw(data, options);
                      }
                    </script>
                  </head>
                  <body>
                    <div id="piechart" style="width: 900px; height: 500px;"></div>
                  </body>
                </html>