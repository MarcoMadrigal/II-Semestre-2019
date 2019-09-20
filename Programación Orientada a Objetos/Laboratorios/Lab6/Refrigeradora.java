class Refrigeradora extends Dispositivos{

    @Override
    public String encender(){
        return "Refrigerador encendido";
    }

    @Override
    public String apagar(){
        return "Refrigerador apagado";
    }

    public String cambiarNivelDeFrio(){
        return "Nivel de frío cambiado";
    }

}