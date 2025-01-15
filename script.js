var tl = gsap.timeline()
tl.from("h1", {
   y: -20,
   opacity: 0,
   delay: 0.5,
   duration: 1
})
tl.from(".content-wrapper p", {
   y: -20,
   opacity: 0,
   delay: 0.5,
   duration: 1
})

const cursor = document.querySelector("#cursor");
const body = document.querySelector("body")

body.addEventListener("mousemove", function (e) {
   gsap.to(cursor, {
      x: e.x, y: e.y
   })
}) 