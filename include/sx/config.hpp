/*
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SX_CONFIG_HPP
#define SX_CONFIG_HPP

#include <map>
#include <string>
#include <libconfig.h++>
#include <sx/utility/compat.hpp>

namespace sx {

#define OBELISK_DEFAULT_URI "tcp://obelisk.unsystem.net:8081"

/**
 * Map to hold configuration settings read from the config file or defaults.
 */
typedef std::map<std::string, std::string> config_map_type;

/**
 * Get a value of the specified type from the configuration object and store it
 * in the specified configuration map. If the setting is not located any 
 * pre-existing setting value is unchanged.
 *
 * @param <T> the type of the configuration setting to read.
 * @param root the root of the configuration settings object to read from.
 * @param map the configuration settings map to write into.
 * @param key the name of the configuration setting to read.
 */
template <typename T>
void get_value(const libconfig::Setting& root, config_map_type& map,
    const std::string& key);

/**
 * Read the configuration file at the specified path.
 *
 * @param config the configuration settings object to write to.
 * @param path the path of the configuration settings file to read.
 * @return true if read successfully, otherwise false.
 */
bool read_config_file(libconfig::Config& config, const tpath path);

/**
 * Determine the proper configuration file path and read the file into the
 * specified configuration settings object.
 *
 * @param config the configuration settings object to write to.
 * @return true if read successfully, otherwise false.
 */
bool read_config(libconfig::Config& config);

/**
 * Get configuration settings from the apparopriate configuration file
 * after setting defaults from memory. Use CZMQ program 'makecert' to generate
 * cert/key settings values.
 *
 * @param map the configuration settings map to write into.
 */
void get_config(config_map_type& map);

/**
 * Validate existence of the specified file and then set the environment 
 * SX_CFG environment variable accordingly.
 *
 * @param path the path of the configuration settings file.
 * @return true if set successfully, otherwise false.
 */
bool set_config_path(std::string& path);

} // sx

#endif