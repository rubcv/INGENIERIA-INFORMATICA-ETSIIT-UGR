<?php 

	if(isset($_POST['disco'])){
		
		$disco = $_POST['disco'];
	}else{
		$disco = "";
	}

	

	echo '<form action = "tienda.php" method="POST">
		<input type="hidden" name="articulos[]" value="'. $disco .'">
			<section class="login_form">
				<br><br>
				Nombre: <br>
				<input type="text" name="nombre">
				<br><br>
				Apellidos: <br>
				<input type="text" name="apellidos">
				<br><br>
				Correo: <br>
				<input type="email" name="email">
				<br><br>
				Teléfono: <br>
				<input type="number" name="telefono"><br><br>
				Dirección: <br>
				<input type="text" name="direccion"> 
				<h4> Datos de pago: </h4>
				<input type="radio" name="pago" value="tarjeta"> Tarjeta 
				<input type="radio" name="pago" value="reembolso"> Contra-reembolso
				<br><br>Número de tarjeta: <br>
				<input type="text" name="tarjeta">
				<br><br>
				Fecha de caducidad: <br>
				<input type="date" name="caducidad"><br><br>
				Código de seguridad: <br>
				<input type="number" name="codtarjeta"> <br><br>
				<br><br>
				<input type="submit" id="buyBtt" value="Realizar compra">
			</section>
		</form>'
			;

?>