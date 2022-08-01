// Variadic function with template --Script 

template<bool x > int reversed_binary_value()
{
    return x  ;
}
template<bool x , bool y , bool... z> int reversed_binary_value()
{
    return (reversed_binary_value<y,z...>() << 1) + x ;
}