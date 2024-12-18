
def generate_get_func_body(n):
    if 1 == n:
        return '''#define GET_FUNC_BODY_1(_1) \\
    if constexpr (0 == N) { return (_1); } '''
    param_vec = [f'_{i}' for i in range(1, n + 1)]
    param_str = ', '.join(param_vec)
    pre_param_str = ', '.join(param_vec[:-1])
    return f"""#define GET_FUNC_BODY_{n}({param_str}) \\
    GET_FUNC_BODY_{n-1}({pre_param_str})    \\
    if constexpr ({n-1} == N) {{ return (_{n}); }} """

def generate_get_fun(n):
    param_vec = [f'_{i}' for i in range(1, n + 1)]
    param_str = ', '.join(param_vec)
    return f'''#define DEFINE_GET_FUNC_{n}({param_str}) \\
    GET_FUNC_HEAD() \\
    GET_FUNC_BODY_{n}({param_str})  \\
    GET_FUNC_TAIL({n-1})    \\
    GET_FUNC_HEAD_CONST()    \\
    GET_FUNC_BODY_{n}({param_str})  \\
    GET_FUNC_TAIL({n-1})'''

for i in range(1,5):
    print(generate_get_func_body(i))
    print(generate_get_fun(i))