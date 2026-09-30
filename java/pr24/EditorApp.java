public class EditorApp {
    private IDocument document;
    private ICreateDocument documentFactory;

    public EditorApp(ICreateDocument documentFactory) {
        this.documentFactory = documentFactory;
        this.document = null;
    }

    public void createNewDocument() {
        document = documentFactory.createNew();
        document.open();
    }

    public void openDocument() {
        document = documentFactory.createOpen();
        document.open();
    }

    public void saveDocument() {
        if (document != null) {
            document.save();
        } else {
            System.out.println("No document open to save.");
        }
    }

    public static void main(String[] args) {
        EditorApp textEditor = new EditorApp(new CreateTextDocument());
        textEditor.createNewDocument();
        textEditor.saveDocument();
        textEditor.openDocument();
        textEditor.saveDocument();
    }
}