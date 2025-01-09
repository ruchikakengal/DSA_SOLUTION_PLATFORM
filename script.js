 var tl = gsap.timeline()
 tl.from("h1", {
    y:-20,
    opacity:0,
    delay:0.5,
    duration:1
 })
 tl.from(".content-wrapper p", {
    y:-20,
    opacity:0,
    delay:0.5,
    duration:1
 })
 function toggleMenu() {
   const navMenu = document.querySelector('.nav .right ul');
   navMenu.classList.toggle('active');
}
