
def generate_size_(n: int):
    any_list = ['Any{}' for i in range(n)]
    any_str = ', '.join(any_list)
    return f'''template <typename T>
constexpr auto size_(tag<{n}>) -> decltype(T{{{any_str}}}, 0u) {{
  return {n}u;
}}'''

def generate_constexpr_for(n: int):
    param_vec = [f'_{i}' for i in range(1, n + 1)]
    param_str = ', '.join(param_vec)
    return f'''  if constexpr (size<T>() == {n}u) {{
    const auto &[{param_str}] = v;
    expand_args(f, {param_str});
  }}'''



def generate_for_func(n: int):
    return f'''
template <typename T, typename F> 
void constexpr_for(const T &v, F&& f) {{
{' '.join([generate_constexpr_for(i) for i in range(n, 0, -1)])}
}}
'''



n = 64
print(generate_for_func(n))
for i in range(n, 2, -1):
    print(generate_size_(i))