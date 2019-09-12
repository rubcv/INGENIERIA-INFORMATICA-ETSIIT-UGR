<!DOCTYPE html>
<html lang="es">
  <head>
    <link rel="stylesheet" href="css/portada-style.css">
    <meta charset="utf-8">
    <title>Usuario: Social Network UGR </title>
    <script src="https://code.jquery.com/jquery-3.2.1.js"> </script>
    <?php 
      
        $EXECUTED = false;
        include("conexiones/sesion.php"); 

        if (!isset($_SESSION["username"])){
          header("location: index.php");
        }

        if(isset($_GET['bienvenida'])){
          echo '<script>
            function openNav() {
                document.getElementById("myNav").style.width = "100%";
                value = document.getElementById("insert_here");
                value.innerHTML = "¡Bienvenido a Social Network UGR!";
             }
            </script>
            ';
          unset($_GET['bienvenida']);
        }
      ?>
      
      <script>
        function closeNav() {
            document.getElementById("myNav").style.width = "0%";
        }
          
      </script>


      <style>
        body {
            margin: 0;
            font-family: 'Lato', sans-serif;
           padding: 0px;    
        }

         .entradas{
          width: 1210px;
          overflow-y:scroll;
        }

        .recent-users {
          overflow-y:scroll;
          z-index: 0.5;
        }
        #recent-user-name {
          font-size: 1.2em;
          margin-bottom: -40px;
          margin-top: -20px;
          text-align: center;
        }
      #entry-user-name {
        font-size: 1.2em;
        margin-bottom: -20px;
        margin-top: 20px;
        text-align: center;
      }
      #entrada-box h5{
        word-wrap: break-word;
      }
      #entrada-box h4{
        font-size: 1em;
        margin-top: -20px;
        margin-bottom: -7px;
      }
        .overlay {
            height: 100%;
            width: 0;
            position: fixed;
            z-index: 1;
            top: 0;
            left: 0;
            background-color: rgb(0,0,0);
            background-color: rgba(0,0,0, 0.9);
            overflow-x: hidden;
            transition: 0.5s;
        }

        .overlay-content {
            position: relative;
            top: 25%;
            width: 100%;
            text-align: center;
            margin-top: 30px;
        }

        .overlay a {
            padding: 8px;
            text-decoration: none;
            font-size: 36px;
            color: #818181;
            display: block;
            transition: 0.3s;
        }

        .overlay a:hover, .overlay a:focus {
            color: #f1f1f1;
        }

        .overlay .closebtn {
            position: absolute;
            top: 20px;
            right: 45px;
            font-size: 60px;
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

          #load{
                  background-color: rgba(255, 0, 0, 0.8);
                  border-radius: 0.7em;
                  height: 50px;
                  width: 100%;
                  text-align: center;
                  text-decoration: none;
                  display: inline-block;
                  font-size: 16px;
          }
          #next_prev {
              text-decoration: none;
              display: inline-block;
              border-style: dashed;
              border-color: lightsalmon;
              border-radius: 50%;
              padding: 8px 16px;
          }

          #next_prev:hover {
              background-color: #ddd;
              color: black;
          }

          .previous {
              background-color: #f1f1f1;
              color: black;
          }

          .next {
              background-color: rgba(119, 244, 66, 0.8);
              color: white;
          }

        </style>

        <script>
            setTimeout(openNav, 1000);
        </script>



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
      <nav> <a href="<?php echo 'usuario.php?usuario=' . $_SESSION['username']  ?>"> Biografía </a> - <a href= "fotos.php" >  Fotos </a> - <a href="<?php echo 'info.php?usuario=' . $_SESSION['username']  ?>"> Información personal </a> </nav>
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
      <?php $pagina = 1; ?> 

    <section class="entradas">
    <button id="load" type="button"> Cargar nuevas entradas </button>
    <?php
      if(isset($_GET['historial'])){
        $indice = $_GET['historial'];
      }else{
        $indice = 0;
      }
        $limit = 6;
        $siguiente = $indice + $limit;
        $anterior = $indice - $indice;
        $consulta = $indice + 6 - 1; // Empieza en 0

        echo "<a id=\"next_prev\" href=\"portada.php?historial=" . $anterior . "\" class=\"previous square\"> &#8249; </a>
              <a id=\"next_prev\" href=\"portada.php?historial=" . $siguiente . "\" class=\"next square\">&#8250;</a>
              ";

          echo "<section id=\"zona_de_entradas\">";
            $siguiente -= 6;
        $sql  = "SELECT DISTINCT entradas.id_ent, usuarios.foto_usuario, entradas.username, usuarios.username, entradas.titulo, entradas.texto, entradas.fecha_public FROM entradas, usuarios WHERE entradas.username = usuarios.username ORDER BY entradas.id_ent DESC LIMIT 6 OFFSET $siguiente;";
         
            $result = $conn->query($sql);
            $array = $result->fetchAll(PDO::FETCH_ASSOC); 

              foreach ($array as $entrada) {
                  $entrada_id = $entrada['id_ent'];
                  $nombre_e = $entrada['username'];
                  $foto_e = $entrada['foto_usuario'];
                  $titulo_e = $entrada['titulo'];
                  $fecha_e = $entrada['fecha_public'];
                  $texto_e = $entrada['texto'];
                  $user_dir = "usuario.php?usuario=" . "$nombre_e";
                  $entrada_dir = "entrada.php?entrada=" . $entrada_id;
            
                  if (strlen($texto_e) > 150)
                      $texto_e = substr($texto_e, 0, 147) . '...';


                      
                  $sql = "SELECT titulo FROM entradas WHERE username = '$nombre_e';";
                    $result = $conn->query($sql);
                    $valores = $result->fetchAll(PDO::FETCH_ASSOC);  

                  $info = "ENTRADAS PUBLICADAS: - ";
                  foreach ($valores as $titulos){
                    $info .= $titulos['titulo'];
                    $info .= " - "; 
                  } 

                  echo "
                  <section class=\"entrada1\" id=\"entrada-box\">
                    <sup>" . "$fecha_e" . " </sup>
                    <a href=" . $user_dir . " id=\"get_content\" title='" . $info . "'>
                      <section  class = \"nombre_entrada\" id=\"entry-user-name\"> <h4>" . $nombre_e . " </h4> </section>
                      <img id=\"recent-user-picture\" src=" . $foto_e . " alt=\"user-picture\">
                    </a>
                      <a href=". $entrada_dir . ">
                      <h3>  " . "$titulo_e" . " </h3>
                      <h5>" . $texto_e . " </h5>
                      </a>
                    </section>
                  ";

            }
            echo "</section>";
        ?>
   </section>
      
      <section id="myNav" class="overlay">
        <a href="javascript:void(0)" class="closebtn" onclick="closeNav()">&times;</a>
        <section class="overlay-content">
          <a id="insert_here"> </a>
        </section>
      </section>

      <script>


        $(document).ready(function () {
                $("#get_content").hover(function (){
                    $('usuario').qtip();
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

             $(document).ready(function() {
              $("#load").click(function(){
                  $.ajax({
                        url: 'conexiones/cargar_entradas.php',
                        data: "",
                        dataType: 'json',
                        success: function(data){
                                    $("#zona_de_entradas").html(
                                      "<section></section>"
                                    );
                                     
                                    for(var fila in data){
                                        var entrada_id = data[fila]['id_ent'];
                                        var nombre_e = data[fila]['username'];
                                        var foto_e = data[fila]['foto_usuario'];
                                        var titulo_e = data[fila]['titulo'];
                                        var fecha_e = data[fila]['fecha_public'];
                                        var texto_e = data[fila]['texto'];
                                        var user_dir = "usuario.php?usuario=" + nombre_e;
                                        var data_dir = "entrada.php?entrada=" + entrada_id;
                                      

                                        $("#zona_de_entradas").append(
                                      
                                              "<section class=" + "entrada1" + " id=" + "entrada-box" + " >" +
                                                "<sup>" + fecha_e + " </sup>" +
                                                "<a href=" + user_dir + " >" +
                                                "<section class=" + "nombre_entrada" + " id=" + "entry-user-name" + ">" + "<h4>" + nombre_e + " </h4> </section>" + 
                                                   "<img id=" + "recent-user-picture " + " src=" +  foto_e + " alt=" + "user-picture" + ">" +
                                                " </a>" +
                                                  "<a href=" + data_dir + " >" + 
                                                  "<h3> " + titulo_e + " </h3>" + 
                                                  "<h5> " + texto_e + " </h5>" +
                                                  "</a>" +
                                                "</section>"
                                                
                                          
                                        );
                                      }
                                    }
                              });    
                          });            
                        });

      </script>

     <section class="bottom-sections">
      <hr>
      <footer class="about"> <a href="red-social/contacto.php"> Contacto </a> - <a href="red-social/como_se_hizo.pdf"> Cómo se hizo </a> </footer>

      </section>
  </body>
</html>
