#include "run_creator.h"

// Constructor calls class constructors of member objects and feeds
// them with the required parameters
RunCreator::RunCreator(const std::string &training_data_path,
                       const std::string &training_label_path,
                       const std::string &test_data_path,
                       const std::string &test_label_path,
                       const std::initializer_list<int> &layer_settings,
                       const float &learning_rate)
    : _mnist_training_data(training_data_path, training_label_path),
      _mnist_test_data(test_data_path, test_label_path),
      _hyper_parameters(layer_settings, learning_rate)
{
}
