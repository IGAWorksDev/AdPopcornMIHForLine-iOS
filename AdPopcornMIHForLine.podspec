Pod::Spec.new do |s|
s.name         = "AdPopcornMIHForLine"
s.version      = "1.0"
s.summary      = "AdPopcornMIHForLine.framework"
s.homepage     = "https://github.com/IGAWorksDev/AdPopcornMIHForLine-iOS"

s.license      = {
:type => 'Commercial',
:text => <<-LICENSE
All text and design is copyright 2006-2016 igaworks, Inc.

All rights reserved.

https://github.com/IGAWorksDev/AdPopcornMIHForLine-iOS
LICENSE
}

s.platform = :ios, '7.0'
s.author       = { "wonje,song" => "ricky@igaworks.com" }
s.source       = { :git => "https://github.com/IGAWorksDev/AdPopcornMIHForLine-iOS.git", :tag => "#{s.version}" }
s.resources = "AdPopcornMIHForLine.bundle"
s.ios.vendored_frameworks = 'AdPopcornMIHForLine.framework'
s.frameworks = 'ImageIO', 'MessageUI', 'SafariServices', 'MediaPlayer', 'AdSupport', 'AVKit', 'CoreMedia', 'AVFoundation'
s.libraries = 'xml2'
s.xcconfig     = { 'HEADER_SEARCH_PATHS' => '"$(SDKROOT)/usr/include/libxml2"' }
end
