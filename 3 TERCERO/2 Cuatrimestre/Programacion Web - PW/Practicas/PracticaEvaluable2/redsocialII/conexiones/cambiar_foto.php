<?php

ob_start();
 session_start();

  include_once 'dbconexion.php';


$target_dir = "../images/usuarios/";
$target_file = $target_dir . basename($_FILES["userfile"]["name"]);
$uploadOk = 1;
$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);
// Check if image file is a actual image or fake image
if(isset($_POST["submit"])) {
    $check = getimagesize($_FILES["userfile"]["tmp_name"]);
    if($check !== false) {

        $uploadOk = 1;
    } else {

        $uploadOk = 0;
    }
}

// Check file size
if ($_FILES["userfile"]["size"] > 50000000000000) {
    $uploadOk = 0;
}
// Allow certain file formats
if($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
&& $imageFileType != "gif" ) {
    $uploadOk = 0;
}
// Check if $uploadOk is set to 0 by an error
if ($uploadOk == 0) {
} else { // if everything is ok, try to upload file
    if (move_uploaded_file($_FILES["userfile"]["tmp_name"], $target_file)) { // Se ha subido la imagen
         $new_path = "images/usuarios/";
         $new_path .= $_FILES["userfile"]["name"];
         $user_name = $_SESSION['username'];

         $sql = "UPDATE `usuarios` SET `foto_usuario` = '$new_path' WHERE `username` = '$user_name';";
         $conn->query($sql);

         $_SESSION['foto_usuario'] = $new_path;




    } else {

    }
}

header('Location: ../info.php?usuario=' . $_SESSION['username']);
