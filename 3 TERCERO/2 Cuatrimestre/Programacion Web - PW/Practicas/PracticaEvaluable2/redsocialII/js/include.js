


    function validar_registro(){
        var elements = document.getElementsByClassName("new-users-form")[0];
        
        var elemento_vacio = false;
        var elementos =  [];
        for (var i = 0, element; element = elements[i++];) {
            if (element.value == ""){
                elementos.push(element);
                elemento_vacio = true;
            }
        }
        
        if(elementos.length == elements.length - 1){
            alert("El formulario no puede estar vacio");
            for(var i = 0; i < elementos.length; i++){
                elementos[i].style.borderColor = "red";
            }
        }else{
            for(var i = 0; i < elementos.length; i++){
                alert(elementos[i].id + " no puede estar vacio");
                elementos[i].style.borderColor = "red";
            }
        }

        if(!elemento_vacio){
            var una_pass = false;
            var previous = "";
            for (var i = 0, element; element = elements[i++];) {
            switch (element.type) {
                case "text":
                    break;
                case "email":
                    if(element.value.indexOf('@gmail.com') === -1){
                        alert("No es una direccion de correo valida ('gmail.com')");
                        element.style.borderColor = "red";
                        elemento_vacio = true;
                    }
                    break;
                case "password":
                        if(previous != ""){
                            if(element.value != previous){
                                alert("Las contraseñas no coinciden");
                                element.style.borderColor = "red";
                                elemento_vacio = true;
                            }
                        }
                        if(element.value.length < 6){
                            if(!una_pass)
                                    alert("La contraseña no es válida, debe tener minimo 6 caracteres");
                            
                            element.style.borderColor = "red";
                            elemento_vacio = true;
                            una_pass = true;
                        }else{
                            previous = element.value;
                        }
                       
                    break;
                default:
                    break;
            }
            }    
        }

        return elemento_vacio?  false : true; /* Para enviar o no los datos con php */
    }
    
function setcookie(name, value, days){
    if (days){
        var date = new Date();
        date.setTime(date.getTime()+days*24*60*60*1000); // ) removed
        var expires = "; expires=" + date.toGMTString(); // + added
    }else
        var expires = "";
    document.cookie = name+"=" + value+expires + ";path=/"; // + and " added
}


    function validar(){
        var elements = document.getElementsByClassName("header-form")[0];
        

        var elemento_vacio = false;
        for (var i = 0, element; element = elements[i++];) {
            if (element.value == ""){
                alert(element.id + " no puede estar vacio");
                element.style.borderColor = " hsl(120, 100%, 75%)";
                elemento_vacio = true;
            }
        }

        if(!elemento_vacio){
            for (var i = 0, element; element = elements[i++];) {
            switch (element.type) {
                case "text":
                    break;
    
                case "password":
                        if(element.value.length < 6){
                            alert("La contraseña no es válida, debe tener minimo 6 caracteres");
                            element.style.borderColor = " hsl(120, 100%, 75%)";
                            elemento_vacio = true;
                        }
                    break;
                default:
                    break;
                }
            }    
    
            
                
        }

        

             var remember_btt = document.getElementById("recordar");
            
            if(!elemento_vacio && remember_btt.checked){
                var session_name = elements[0].value;
                var session_pass = elements[1].value;
                
                
                setcookie("name", session_name, 10 );
                setcookie("pass", session_pass, 10 );
               
            }

    


        return elemento_vacio?  false : true; /* Para enviar o no los datos con php */
    }
    

function confirmacion(){
    
        if(confirm("¿Quieres publicar la entrada?") == true){
            return true;
        }else{
            return false;
        }
}

function guardar_cambios(){
     if(confirm("¿Guardar los cambios?") == true){
            return true;
        }else{
            return false;
        }
}

function borrar_usuario(){
     if(confirm("Borrar el usuario borrara tambien sus entradas asociadas, ¿Continuar?") == true){
            return true;
        }else{
            return false;
        }
}


function amistad(){
     if(confirm("¿Deseas agregar a este usuario como amigo?") == true){
            return true;
        }else{
            return false;
        }
}

function confirmacion_entrada(){
     if(confirm("¿Publicar entrada?") == true){
            return true;
        }else{
            return false;
        }
}

function confirmacion_comentario(){
     if(confirm("¿Publicar comentario?") == true){
            return true;
        }else{
            return false;
        }
}

