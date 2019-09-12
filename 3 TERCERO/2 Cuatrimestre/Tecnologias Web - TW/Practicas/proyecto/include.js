function validate(form){
    var result = confirm("Confirmar esta compra?");

    if(!result){
        return false;
    }else{

        var nombre = $("input[name=nombre]").val();
        var apellidos = $("input[name=apellidos]").val();
        var email = $("input[name=email]").val();
        var telefono = $("input[name=telefono]").val();
        var direccion = $("input[name=direccion]").val();
        var pago = $("input[name=pago]").val();
        var tarjeta = $("input[name=tarjeta]").val();
        var caducidad = $("input[name=caducidad]").val();
        var codtarjeta = $("input[name=codtarjeta]").val();

        if (!/^[a-zA-Z]+$/.test(nombre)){
            alert("El nombre " + nombre + " contiene caracteres no válidos");
            return false;
        }

        if (!/^[a-zA-Z]+$/.test(apellidos)){
            alert("El nombre " + apellidos + " contiene caracteres no válidos");
            return false;
        }
        
        var re = /\S+@\S+\.\S+/;
        if(!re.test(email)){
            alert("Email no válido");
            return false;
        }
        
        if (/^[a-zA-Z]+$/.test(telefono) || telefono.length != 9){
            alert("El teléfono no es válido");
            return false;
        }


        var d1 = new Date();
        var d2 = new Date(caducidad);
        if(d1.getTime() > d2.getTime()){
            alert("Fecha de caducidad no válida");
            return false;
        }
        
        if (/^[a-zA-Z]+$/.test(codtarjeta)){
            alert("El código de la tarjeta no es válido");
            return false;
        }

    }
}


function validarTexto(texto){
    if(texto != ""){

        if (!/^[a-zA-Z]+$/.test(texto)){
            alert( texto + " r contiene caracteres no válidos");
            return false;
        }
    }
        return true;
}


function validarNumero(numero){
    if(numero != ""){

        if (/^[a-zA-Z]+$/.test(numero)){
            alert( numero + " contiene caracteres no válidos");
            return false;
        }
        return true;
    }
    return true;
}

function validarEmail(email) {
    var re = /^(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    return re.test(email);
}


function validarTelefono(telf){
    return (validarNumero(telf) && telf.length == 9);
}

