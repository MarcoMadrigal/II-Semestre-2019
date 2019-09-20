class Microondas extends Dispositivos{

    public String iniciar(){
        return "Iniciando...";
    }

    public String parar(){
        return "Su comida está lista";
    }

    @Override
    public String encender(){
        return "Microondas encendido";
    }

    @Override
    public String apagar(){
        return "Microondas apagado";
    }

}