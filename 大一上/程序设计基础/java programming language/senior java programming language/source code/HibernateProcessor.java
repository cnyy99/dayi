import org.w3c.dom.Document;

import javax.annotation.processing.AbstractProcessor;
import javax.annotation.processing.RoundEnvironment;
import javax.annotation.processing.SupportedAnnotationTypes;
import javax.annotation.processing.SupportedSourceVersion;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.Element;
import javax.lang.model.element.ElementKind;
import javax.lang.model.element.Name;
import javax.lang.model.element.TypeElement;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.OutputKeys;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.PrintWriter;
import java.util.Set;

/**
 * Created by cuixiaohui on 2016/3/30.
 */

@SupportedSourceVersion(SourceVersion.RELEASE_8)
@SupportedAnnotationTypes({"Id","Property","Persistent"})
public class HibernateProcessor extends AbstractProcessor {
    @Override
    public boolean process(Set<? extends TypeElement> annotations, RoundEnvironment roundEnv)  {
        try{
            for(Element t : roundEnv.getElementsAnnotatedWith(Persistent.class)){
                Name clazzName = t.getSimpleName();
                Persistent per = t.getAnnotation(Persistent.class);
                DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
                DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
                Document document = documentBuilder.newDocument();
                document.setXmlVersion("1.0");
                org.w3c.dom.Element rootElement = document.createElement("hibernate-mapping");
                org.w3c.dom.Element classElement = document.createElement("class");
                classElement.setAttribute("name",t.toString());
                classElement.setAttribute("table",per.table());
                for(Element f : t.getEnclosedElements()){
                    if(f.getKind() == ElementKind.FIELD){
                        Id id = f.getAnnotation(Id.class);
                            if(id != null){
                                org.w3c.dom.Element idElement = document.createElement("id");
                                idElement.setAttribute("name",f.getSimpleName().toString());
                                idElement.setAttribute("column",id.column());
                                idElement.setAttribute("type",id.type());
                                classElement.appendChild(idElement);
                        }

                        Property property = f.getAnnotation(Property.class);
                        if(property != null){
                            org.w3c.dom.Element propertyElement = document.createElement("property");
                            propertyElement.setAttribute("name",f.getSimpleName().toString());
                            propertyElement.setAttribute("column",property.column());
                            propertyElement.setAttribute("type",property.type());
                            classElement.appendChild(propertyElement);
                        }
                    }
                }

                rootElement.appendChild(classElement);
                document.appendChild(rootElement);

                TransformerFactory tf = TransformerFactory.newInstance();
                Transformer transformer = tf.newTransformer();
                DOMSource source = new DOMSource(document);
                transformer.setOutputProperty(OutputKeys.ENCODING,"UTF-8");
                transformer.setOutputProperty(OutputKeys.INDENT,"yes");
                transformer.setOutputProperty(OutputKeys.DOCTYPE_PUBLIC,"hibernate");
                PrintWriter pw = new PrintWriter(clazzName+"hbm.xml");
                StreamResult result = new StreamResult(pw);
                transformer.transform(source,result);
                System.out.println("Succeed generating files!");

            }

        }catch(Exception ex){
            ex.printStackTrace();
        }
        return  true;
    }
}
