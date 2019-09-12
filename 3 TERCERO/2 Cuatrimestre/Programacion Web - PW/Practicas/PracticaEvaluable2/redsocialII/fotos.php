<!DOCTYPE html>
<html lang="es">
  <head>
    <link rel="stylesheet" href="css/fotos-style.css">
    <meta charset="utf-8">
    <title>Usuario: Social Network UGR </title>

    <script src="https://code.jquery.com/jquery-3.2.1.js"> </script>
    <?php
         include("conexiones/sesion.php"); 
        
        if (!isset($_SESSION["username"])){
          header("location: index.php");
        }
    ?>
    <script src="js/include.js"> </script>
    <script>
      var e = document.getElementById('parent');
            e.onmouseover = function() {
              document.getElementById('popup').style.display = 'block';
            }
            e.onmouseout = function() {
              document.getElementById('popup').style.display = 'none';
            }
    </script>

      <style>
        body {
            margin: 0;
            font-family: 'Lato', sans-serif;
        }
        .entradas{
            width: 1210px;
            overflow-y:scroll;
        }
        #entrada-img{
          width: 350px;
          height: 200px;
        }

          .button {
              position: relative;
              background-color: rgba(244, 152, 66, 0.9);
              border: dashed;
              font-size: 18px;
              color: #FFFFFF;
              padding-right: 20px;
              width: 150px;
              height: 100px;
              margin-left:-18px;
              text-align: center;
              transition-duration: 0.4s;
              text-decoration: none;
              overflow: hidden;
              cursor: pointer;
          }

          .button:after {
              content: "";
              background: #f1f1f1;
              display: block;
              position: absolute;
              padding-top: 300%;
              padding-left: 350%;
              margin-left: -20px;
              margin-top: -120%;
              opacity: 0;
              transition: all 0.8s
          }

          .button:active:after {
              padding: 0;
              margin: 0;
              opacity: 1;
              transition: 0s
          }
          .recent-users {
          overflow-y:scroll;
          z-index: 0.5;
        }
    </style>
  </head>
  <body>
    
     <section class="top-header">
      <a href="portada.php">
      <img src="images/logo.png" alt="Social Network UGR">
      <h1 class="header-letters" id="header-with-transition"> Social Network UGR </h1>
      </a>
      <?php $usuario = $_SESSION['username']; $user_profile = "usuario.php?usuario=" . $_SESSION['username']; ?>
      <a href="<?php echo $user_profile ?>">
      <b class="username"> <?php echo $_SESSION['username'] ?> </b>
       <img class="user-image" src= "<?php echo $_SESSION['foto_usuario'] ?>" alt="Social Network UGR">
      </a>
      <a href="conexiones/salir.php" class="back-to-index"> Bye, Bye... </a>
    </section>
    <section class="portada-menu">
      <nav> <a href="<?php echo 'usuario.php?usuario=' . $_SESSION['username']  ?>"> Biografía </a> - <a href="fotos.php"> Fotos </a> - <a href="<?php echo 'info.php?usuario=' . $_SESSION['username']  ?>"> Información personal </a> </nav>
      <hr>
    </section>


    <section class="friends-menu">
      <section class="main">

      <?php 
        $sql  = "SELECT usuarios.username, usuarios.foto_usuario, entradas.username, entradas.fecha_public FROM entradas, usuarios WHERE usuarios.username = entradas.username GROUP BY entradas.username HAVING entradas.fecha_public >= CURDATE()-10 ORDER by count(*) DESC;";
        $result = $conn->query($sql);
        $array = $result->fetchAll(PDO::FETCH_ASSOC);     


        foreach ($array as $muro_fama) {
           $nombre_f = $muro_fama['username'];
           $foto_f = $muro_fama['foto_usuario'];
           $user_dir = "usuario.php?usuario=" . "$nombre_f";
            
             $sql = "SELECT titulo FROM entradas WHERE username = '$nombre_f';";
                $result = $conn->query($sql);
                $valores = $result->fetchAll(PDO::FETCH_ASSOC);  

              $info = "ENTRADAS PUBLICADAS: - ";
              foreach ($valores as $titulos){
                $info .= $titulos['titulo'];
                $info .= " - "; 
              } 


            echo "
            <section id=\"column\">
            <a href=" . $user_dir . " id=\"get_content\" title='" . $info . "'>
              <section id=\"user-name\"> <h3> " . $nombre_f . " </h3> </section>
              <img id=\"user-picture\" src=" . $foto_f . " alt=\"user-picture\">
            </a>
            </section>";

        }



       ?>


    </section>
    </section>

  
    <section class="recent-users">
    <button type="button" class="button" id="usuarios_activos"> USUARIOS ACTIVOS </button>
      

      <section id="recent-users-profiles">
         <?php
          $sql  = "SELECT username, foto_usuario FROM usuarios WHERE activo = 1;";
           $result = $conn->query($sql);
           $array = $result->fetchAll(PDO::FETCH_ASSOC);   

        foreach ($array as $recent) {
              $nombre_r = $recent['username'];
              $foto_r = $recent['foto_usuario'];
              $user_dir = "usuario.php?usuario=" . "$nombre_r";
              
              $sql = "SELECT titulo FROM entradas WHERE username = '$nombre_r';";
                $result = $conn->query($sql);
                $valores = $result->fetchAll(PDO::FETCH_ASSOC);  

              $info = "ENTRADAS PUBLICADAS: - ";
              foreach ($valores as $titulos){
                $info .= $titulos['titulo'];
                $info .= " - "; 
              }

              echo  "
                  <a href=" . $user_dir . " id=\"get_content\" title='" . $info . "'>
                    <section id=\"recent-user-name\"> <h5> " . $nombre_r . "  </h5> </section>
                    <img id=\"recent-user-picture\" src=" . $foto_r . " alt=\"user-picture\">
                  </a>";

        }


      ?>
      </section>
    </section>

    <section class="entradas">
        <?php
            $sql = "SELECT id_ent, media_ent FROM entradas WHERE media_ent != '';";
                 $result = $conn->query($sql);
                 $array = $result->fetchAll(PDO::FETCH_ASSOC);   

            
        foreach ($array as $media) {
              $pic = $media['media_ent'];
              $entrada_id = $media['id_ent'];
              $entrada_dir = "entrada.php?entrada=" . "$entrada_id";

              echo "<a href=" . $entrada_dir . ">";

              if(strpos($pic, 'youtube') !== false){
                      echo "<iframe id=\"video\" width=\"354\" height=\"154\" src=" . $pic . " frameborder=\"0\" allowfullscreen></iframe>";
              }else{
                        echo "<img id=\"entrada-img\" src=". $pic . " alt=\"Entrada\">";
              }
              echo "</a>";
        }
        ?>
    </section> 
      
       <script>

   $(document).ready(function() {
                    $('#play-video').on('click', function(ev) {
                    
          $("#video")[0].src += "&autoplay=1";
          ev.preventDefault();
      
      });
      });


          $(document).ready(function() {
              $("#usuarios_activos").click(function(){
                  $.ajax({
                        url: 'conexiones/usuarios_activos.php',
                        data: "",
                        dataType: 'json',
                        success: function(data){
                                    $("#recent-users-profiles").html(
                                      "<section></section>"
                                    );
                                    for(var usuario in data){
                                      var name = data[usuario]['username'];
                                      var pic = data[usuario]['foto_usuario'];
                                      var user_dir = "usuario.php?usuario=" + name;

                                      $("#recent-users-profiles").append(

                                          "<a href=" + user_dir + " >" +
                                              "<section id=" + "parent" + ">" +
                                              "<section id=" + "recent-user-name" + "> <h5> " + name + "  </h5> </section>" +
                                              "<img id=" + "recent-user-picture " + "src=" +  pic + " alt=" + "user-picture" + ">" +
                                              "<p id=" + "popup" +  "style=" + "display: none" + "> </p>" +
                                              "</section>" +
                                            "</a>"

                                      );
                                    }
                                 }
                  });    
              });            
            });

          $(document).ready(function () {
                $("#get_content").hover(function (){
                    $('usuario').qtip();
                });
            });

      </script>
  
     <section class="bottom-sections">
      <hr>
      <footer class="about"> <a href="red-social/contacto.php"> Contacto </a> - <a href="../red-social/como_se_hizo.pdf"> Cómo se hizo </a> </footer>
      </section>
  </body>
</html>
 
