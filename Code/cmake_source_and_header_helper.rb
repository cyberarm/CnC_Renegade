directory = ARGV.shift
pp directory

sources = Dir.glob("#{directory}/*.cpp").map { |f| File.basename(f) }
headers = Dir.glob("#{directory}/*.h").map { |f| File.basename(f) }

puts "SOURCES:"
puts sources.join("\n")
puts

puts "HEADERS:"
puts headers.join("\n")
puts

