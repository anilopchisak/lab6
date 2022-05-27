#pragma once

#include <map>
#include <string>
#include <sstream>
#include <vector>
#include "glfx.h"

int glfxparse();
int glfxlex();

namespace glfxParser {

using namespace std;

enum ShaderType {
    VS,
    TC,
    TE,
    GS,
    FS,
    CS,
    NUM_OF_SHADER_TYPES
};

class Program {
public:
    struct Shader {
        string  name;
        string  src;
    };

    Program(const map<ShaderType, Shader>& shaders);
    unsigned CompileAndLink(string& log) const;
        
private:
    int CompileShader(unsigned shader, const Shader& shaderSrc, ostringstream& sLog) const;

    Shader  m_shaders[NUM_OF_SHADER_TYPES];
    bool    m_separable;

    friend int ::glfxparse();
};

class Sampler {
    map<string, string>     m_stringParams;
    map<string, unsigned>   m_intParams;
    map<string, float>      m_floatParams;

    map<string, unsigned>   m_cmpModes;
    map<string, unsigned>   m_compareFuncs;
    map<string, unsigned>   m_minFilters;
    map<string, unsigned>   m_magFilters;
    map<string, unsigned>   m_wrapModes;

public:
    Sampler();
    string Descriptor() const;
    void SetParam(const string& param, const string& val);
    void SetParam(const string& param, unsigned val);
    void SetParam(const string& param, float val);
    unsigned CreateSamplerObject() const;
};

class Effect {
    map<string, Program*>   m_programs;
    vector<string>          m_programNames;
    map<string, Sampler*>   m_samplers;
    map<string, string>     m_shaders;
    struct InterfaceDcl {
        string id;
        int atLine;

        InterfaceDcl(string s, int l) : id(s), atLine(l) {}
        InterfaceDcl() {}
    };
    map<string, InterfaceDcl>   m_interfaces;
    ostringstream               m_sharedCode;
    ostringstream               m_log;
    int                         m_includes;
    bool                        m_active;
    string                      m_dir;
    
public:
    ostringstream& Log();
    unsigned BuildProgram(const string& prog, string& log) const;
    unsigned BuildProgram(const string& prog) const;
    unsigned CreateSampler(const string& sampler) const;
    const vector<string>& GetProgramList() const;
    void PopulateProgramList();
    bool& Active();
    string& Dir();
    ~Effect();
    Effect();

    friend int ::glfxparse();
    friend int ::glfxlex();
};

extern Effect *gEffect;

} // glfxParser
