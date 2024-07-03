#include "Serializer.hpp"

int main(void)
{
    Data data;

    data.showInfos();
    uintptr_t deserializedData = Serializer::serialize(&data);
    std::cout << "Data serialized" << std::endl;
    std::cout << deserializedData << std::endl;

    std::cout << "--------------------" << std::endl;

    Data *serializedData = Serializer::deserialize(deserializedData);
    std::cout << "Data deserialized" << std::endl;
    serializedData->showInfos();
}