package util;

import com.mongodb.MongoClientSettings;
import com.mongodb.client.MongoClient;
import com.mongodb.client.MongoClients;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoCursor;
import com.mongodb.client.MongoDatabase;
import com.mongodb.client.result.DeleteResult;
import java.util.ArrayList;
import java.util.List;
import org.bson.Document;
import org.bson.codecs.configuration.CodecRegistry;
import org.bson.codecs.pojo.PojoCodecProvider;

/**
 * Classe responsável pela persistência de objetos. 
 * @author José
 */
public class Dao <T> {

    private final String URI = "mongodb://localhost:27017";
    private final String DATABASE = "fazenda"; 
    private final MongoClient mongoClient;
    private final MongoDatabase database; 
    private final String colecao;  // nome da coleção 
    private final MongoCollection<T> collection; 
    
    public Dao(Class<T> classe){
        this.colecao = classe.getName(); 
        mongoClient = MongoClients.create(URI);
        CodecRegistry pojoCodecRegistry = org.bson.codecs.configuration.
                CodecRegistries.fromRegistries(MongoClientSettings.getDefaultCodecRegistry(), 
                        org.bson.codecs.configuration.CodecRegistries.
                                fromProviders(PojoCodecProvider.builder().automatic(true).build()));
        database = mongoClient.getDatabase(DATABASE).withCodecRegistry(pojoCodecRegistry);  
        collection = database.getCollection(colecao, classe); 
    }
    
    public void alterar(String chave, String valor, T novo){
        collection.replaceOne(new Document(chave, valor), novo);        
    }
    
    public boolean excluir(String chave, String valor){
        Document filter = new Document(chave, valor);
        DeleteResult result = collection.deleteOne(filter);
        return result.getDeletedCount() > 0;
    }
    
    /**
     * Retorna o objeto cuja chave for igual ao valor passado. 
     * @param chave o campo pelo qual o objeto vai ser buscado
     * @param valor o valor da chave
     * @return O objeto correspondente à chave ou null caso não exista. 
     */
    public T buscarPorChave(String chave, String valor){ 
         T retorno = collection.find(new Document(chave, valor)).first();
         return retorno;
    }
    
    public void inserir(T objeto){       
        collection.insertOne(objeto); 
    }
    
    
    public List<T> listarTodos(){
        ArrayList<T> todos = new ArrayList();          
        MongoCursor<T> cursor = collection.find().iterator();
        while(cursor.hasNext()){
            T elemento = (T)cursor.next();
            todos.add(elemento);
        } 
        return todos; 
    }
    
    
}
