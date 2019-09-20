class Lavadora extends Dispositivos{


    @Override
    public String encender(){
        return "Lavadora encendida";
    }
    
    @Override
    public String apagar(){
        return "Lavadora apagada";
    }

    public String lavar(){
        return "Lavando...";
    }

    public String lavadoSuave(){
        return "Lavado suave seleccionado";
    }

    public String lavadoMedio(){
        return "Lavado medio seleccionado";
    }

    public String lavadoFuerte(){
        return "Lavado fuerte seleccionado";
    }
    
}