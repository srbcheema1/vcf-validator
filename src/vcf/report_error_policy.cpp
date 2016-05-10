/**
 * Copyright 2014-2015 EMBL - European Bioinformatics Institute
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "vcf/error_policy.hpp"

namespace ebi
{
  namespace vcf
  {

    void ReportErrorPolicy::handle_fileformat_section_error(ParsingState & state, std::string message)
    {
        state.m_is_valid = false;
        std::cerr << FileformatError(state.n_lines, message).what() << std::endl;
    }

    void ReportErrorPolicy::handle_meta_section_error(ParsingState & state, std::string message)
    {
        state.m_is_valid = false;
        std::cerr << MetaSectionError(state.n_lines, message).what() << std::endl;
    }

    void ReportErrorPolicy::handle_header_section_error(ParsingState & state, std::string message)
    {
        state.m_is_valid = false;
        std::cerr << HeaderSectionError(state.n_lines, message).what() << std::endl;
    }

    void ReportErrorPolicy::handle_body_section_error(ParsingState & state, std::string message)
    {
        state.m_is_valid = false;
        std::cerr << BodySectionError(state.n_lines, message).what() << std::endl;
    }

    
    void ReportErrorPolicy::handle_fileformat_section_warning(ParsingState const & state, std::string message)
    {
        std::cerr << FileformatError(state.n_lines, message + " (warning)").what() << std::endl;
    }

    void ReportErrorPolicy::handle_meta_section_warning(ParsingState const & state, std::string message)
    {
        std::cerr << MetaSectionError(state.n_lines, message + " (warning)").what() << std::endl;
    }

    void ReportErrorPolicy::handle_header_section_warning(ParsingState const & state, std::string message)
    {
        std::cerr << HeaderSectionError(state.n_lines, message + " (warning)").what() << std::endl;
    }

    void ReportErrorPolicy::handle_body_section_warning(ParsingState const & state, std::string message)
    {
        std::cerr << BodySectionError(state.n_lines, message + " (warning)").what() << std::endl;
    }

  }
}


