package estudosChat.questoesDaProva;

public class ExcecaoExclusao extends Exception {
    public ExcecaoExclusao() {
        super("Objeto não pode ser excluido");
    }
}

/*public void excluir(T objeto) throws ExcecaoExclusao{
    manager...
    entity...
    try{
        manager.remove(objeto);
    } catch(ExcecaoExclusao e){
        throw new ExcecaoExclusao();
    }finally{
        manager.close();
    }
}


public getFirst <T> (lista[] <>){
    return lista<>[0];
} */