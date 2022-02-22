#pragma once

// See: https://rapidjson.org/
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <string>
#include <map>

namespace Core {

	// An interface like class that deals with object loading and saving using JSON
	class Storable
	{
		// Save the object to the filepath
		bool Save(std::string filepath);

		// Load the object from the filepath
		bool Load(std::string filepath);

	protected:
		// Returns the JSON format of the object 
		virtual std::string ToStorable() = 0;

		// Loads the object from the given json
		virtual bool FromStorable(std::string data) = 0;
	};
}
