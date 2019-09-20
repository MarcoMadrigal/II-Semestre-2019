class ExtractorDeAire extends Dispositivos{
    
    @Override
    public String encender(){
        return "Extractor encendido";
    }

    @Override
    public String apagar(){
        return "Extractor apagado";
    }

    public String cambiarVelocidad(){
        return "Velocidad del extractor cambiada";
    }
}