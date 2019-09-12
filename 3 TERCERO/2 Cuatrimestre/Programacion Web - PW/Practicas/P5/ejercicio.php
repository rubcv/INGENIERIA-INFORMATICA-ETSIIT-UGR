<!DOCTYPE html>
<html lang="es">
    <?php


        $IVA = 0.21;
        $precio = 50;
        $precio_total = $precio += ($precio * $IVA);

        echo "\nPrecio total: $precio_total\n";
        
    ?>
</html>