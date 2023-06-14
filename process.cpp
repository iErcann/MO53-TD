process::process(storage_type* storage, loader* loader, calculation* calculation, writer* writer)
    : _storage(storage), _loader(loader), _calculation(calculation), _writer(writer) {}

process::~process() {
    // Libérer la mémoire des objets utilisés par la classe process
    delete _storage;
    delete _loader;
    delete _calculation;
    delete _writer;
}

void process::execute() {
    // Charger les données
    _storage->load();

    // Effectuer le calcul
    double result = _calculation->calculate(_storage);

    // Écrire les résultats
    _writer->write(result);
}