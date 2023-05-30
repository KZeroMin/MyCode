#include <vector>
#include <string>

using Network = std::vector<std::vector<int>>;

auto make_network_from_file(std::string const& fname) -> Network;

auto make_network(int const& node, int const& edge, std::vector<std::string>& inputs) -> Network;

auto get_parameter(std::vector<std::string>& inputs) -> std::vector<int>;

auto get_node(std::string nodes) -> std::vector<int>;

auto set_connection(Network& net, int const& edge, std::vector<std::string>& inputs) -> void;


