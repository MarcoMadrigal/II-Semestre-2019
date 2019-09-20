class Televisor extends Dispositivos{

    @Override
    public String encender(){
        return "Televisor encendido";
    }

    @Override
    public String apagar(){
        return "Televisor apagado";
    }

    public String bajarVolumen(){
        return "Volumen bajado";
    }

    public String subirVolumen(){
        return "Volumen subido";
    }

    public String cambiarCanal(){
        return "Canal cambiado";
    }
}