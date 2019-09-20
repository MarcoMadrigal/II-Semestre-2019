class Ducha extends Dispositivos{

    @Override
    public String encender(){
        return "Ducha encendida";
    }

    @Override
    public String apagar(){
        return "Ducha apagada";
    }

    public String cambiarTemperatura(){
        return "Temperatura cambiada";
    }
}