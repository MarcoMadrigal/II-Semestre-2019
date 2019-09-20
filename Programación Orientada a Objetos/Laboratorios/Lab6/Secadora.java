class Secadora extends Dispositivos{

    @Override
    public String encender(){
        return "Secadora encendida";
    }
    
    @Override
    public String apagar(){
        return "Secadora apagada";
    }
    
    public String tiempo(){
        return "Tiempo seleccionado, iniciando...";
    }

}