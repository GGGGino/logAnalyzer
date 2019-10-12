//
// Created by david ginanni on 06/01/2019.
//

#ifndef LOGANALYZER_DATAWRAPPER_H
#define LOGANALYZER_DATAWRAPPER_H

namespace log_analyzer {
    template <typename DataType>
    struct DataWrapper {
        DataType dato;

        explicit DataWrapper(dato_): dato(dato_);
    };
}

#endif //LOGANALYZER_DATAWRAPPER_H
