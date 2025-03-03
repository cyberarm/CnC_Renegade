# Detect mixed case files and downcase them!

require "fileutils"

Dir.glob("*/*.{h,cpp,c}").each do |file|
  if File.basename(file).downcase != File.basename(file)
    pp [file, "#{File.dirname(file)}/#{File.basename(file).downcase}"]
    
    FileUtils.mv(file, "#{File.dirname(file)}/#{File.basename(file).downcase}")
  end
end

# Detect mix case folders and downcase them!

Dir.glob("*").each do |file|
  next unless File.directory?(file)
  next unless file.downcase != file
  
   pp [file, file.downcase]
  
  FileUtils.mv(file, file.downcase)
end
