#include <iostream>
#include <iomanip>

#include "run_creator.h"

// Constructor calls class constructors of member objects and feeds
// them with the required parameters
RunCreator::RunCreator(const std::string &training_data_path,
                       const std::string &training_label_path,
                       const std::string &test_data_path,
                       const std::string &test_label_path,
                       const std::initializer_list<int> &layer_settings,
                       const int &batch_size,
                       const int &epochs,
                       const float &learning_rate)
    : _mnist_training_data(training_data_path, training_label_path),
      _mnist_test_data(test_data_path, test_label_path),
      _hyper_parameters(layer_settings, batch_size, epochs, learning_rate)
{
}

void RunCreator::show_summary()
{
  std::cout << std::setw(10) << std::left << "DATA SETS" << "\n";
  std::cout << std::setw(10) << std::left << "Training: " << std::setw(8) << std::right << _mnist_training_data.data_dimension_values()[0] << " images\n";
  std::cout << std::setw(10) << std::left << "Test: " << std::setw(8) << std::right << _mnist_test_data.data_dimension_values()[0] << " images\n\n";

  std::cout << std::setw(10) << std::left << "LAYERS" << "\n";
  std::cout << std::setw(10) << std::left << "Total: " << std::setw(8) << std::right << _hyper_parameters.neurons_per_layer().size() << "\n";
  std::cout << std::setw(10) << std::left << "Hidden: " << std::setw(8) << std::right << _hyper_parameters.neurons_per_layer().size() - 2 << "\n";

  std::cout << std::setw(10) << std::left << "Layer: ";
  for (int i; i<_hyper_parameters.neurons_per_layer().size(); i++) {
    std::cout << std::setw(8) << std::right << i+1;
  }
  std::cout << std::endl;
  
  std::cout << std::setw(10) << std::left << "Neurons: ";
  for (int i : _hyper_parameters.neurons_per_layer()) {
    std::cout << std::setw(8) << std::right << i;
  }
  std::cout << std::endl;

  std::cout << std::setw(16) << std::left << "\nMISC" << "\n";
  std::cout << std::setw(16) << std::left << "Learning Rate: " << std::setw(8) << std::right << _hyper_parameters.learning_rate() << "\n";
  std::cout << std::setw(16) << std::left << "Batch Size: "  << std::setw(8) << std::right << _hyper_parameters.batch_size() << "\n";
  std::cout << std::setw(16) << std::left << "Epochs: "  << std::setw(8) << std::right << _hyper_parameters.epochs() << "\n";

  std::cout << std::endl;
}
