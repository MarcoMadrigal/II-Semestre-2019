class Computadora extends Dispositivos{

    @Override
    public String encender(){
        return "Computadora encendida";
    }
    
    @Override
    public String apagar(){
        return "Computadora apagada";
    }

    public String reiniciar(){
        return "Reiniciando...";
    }

    public String cambiarVolumen(){
        return "Volumen cambiado...";
    }

}